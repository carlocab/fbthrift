/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/compiler/sema/standard_mutator.h>

#include <thrift/compiler/lib/cpp2/util.h>
#include <thrift/compiler/sema/patch_mutator.h>
#include <thrift/compiler/sema/standard_mutator_stage.h>

namespace apache {
namespace thrift {
namespace compiler {

constexpr auto kTerseWriteUri = "facebook.com/thrift/annotation/TerseWrite";
constexpr auto kSetGenerated = "facebook.com/thrift/annotation/SetGenerated";
constexpr auto kInjectMetadataFieldsUri =
    "facebook.com/thrift/annotation/InjectMetadataFields";

// TODO(afuller): Instead of mutating the AST, readers should look for
// the interaction level annotation and the validation logic should be moved to
// a standard validator.
void propagate_process_in_event_base_annotation(
    diagnostic_context& ctx, mutator_context&, t_interaction& node) {
  for (auto* func : node.get_functions()) {
    func->set_is_interaction_member();
    ctx.failure_if(
        func->has_annotation("thread"),
        "Interaction methods cannot be individually annotated with "
        "thread='eb'. Use process_in_event_base on the interaction instead.");
  }
  if (node.has_annotation("process_in_event_base")) {
    ctx.failure_if(
        node.has_annotation("serial"), "EB interactions are already serial");
    for (auto* func : node.get_functions()) {
      func->set_annotation("thread", "eb");
    }
  }
}

void remove_param_list_field_qualifiers(
    diagnostic_context& ctx, mutator_context&, t_function& node) {
  for (auto& field : node.params().fields()) {
    switch (field.qualifier()) {
      case t_field_qualifier::none:
        continue;
      case t_field_qualifier::required:
        ctx.warning(node, "optional keyword is ignored in argument lists.");
        break;
      case t_field_qualifier::optional:
        ctx.warning(node, "required keyword is ignored in argument lists.");
        break;
      case t_field_qualifier::terse:
        ctx.warning(
            node,
            "@thrift.TerseWrite annotation is ignored in argument lists.");
        break;
    }
    field.set_qualifier(t_field_qualifier::none);
  }
}

// Only an unqualified field is eligible for terse write.
void mutate_terse_write_annotation_field(
    diagnostic_context& ctx, mutator_context&, t_field& node) {
  const t_const* terse_write_annotation =
      node.find_structured_annotation_or_null(kTerseWriteUri);

  if (terse_write_annotation) {
    auto qual = node.qualifier();
    ctx.check(qual == t_field_qualifier::none, [&](auto& o) {
      o << "`@thrift.TerseWrite` cannot be used with qualified fields. Remove `"
        << (qual == t_field_qualifier::required ? "required" : "optional")
        << "` qualifier from field `" << node.name() << "`.";
    });
    node.set_qualifier(t_field_qualifier::terse);
  }
}

// Only an unqualified field is eligible for terse write.
void mutate_terse_write_annotation_struct(
    diagnostic_context& ctx, mutator_context&, t_struct& node) {
  if (ctx.program().inherit_annotation_or_null(node, kTerseWriteUri)) {
    for (auto& field : node.fields()) {
      if (field.qualifier() == t_field_qualifier::none) {
        field.set_qualifier(t_field_qualifier::terse);
      }
    }
  }
}

// TODO(dokwon): Add a standard mutator test for @internal.InjectMetadataFields.
void mutate_inject_metadata_fields(
    diagnostic_context& ctx, mutator_context&, t_struct& node) {
  // TODO(dokwon): Currently field injection doesn't work for structs used as
  // transitive annotations. Skipping as a workaround.
  if (is_transitive_annotation(node)) {
    return;
  }

  const t_const* annotation =
      node.find_structured_annotation_or_null(kInjectMetadataFieldsUri);
  if (!annotation) {
    return;
  }

  std::string type_string;
  try {
    type_string =
        annotation->get_value_from_structured_annotation("type").get_string();
  } catch (const std::exception& e) {
    ctx.failure([&](auto& o) { o << e.what(); });
    return;
  }
  // If the specified type and annotation are from the same program, append
  // the current program name.
  if (type_string.find(".") == std::string::npos) {
    type_string = annotation->program()->name() + "." + type_string;
  }

  const auto* ttype = node.program()->scope()->find_type(type_string);
  if (!ttype) {
    ctx.failure([&](auto& o) {
      o << "Can not find expected type `" << type_string
        << "` specified in `@internal.InjectMetadataFields` in the current scope."
        << " Please check the include.";
    });
    return;
  }

  const auto* structured = dynamic_cast<const t_struct*>(ttype);
  // We only allow injecting fields from a struct type.
  if (structured == nullptr || ttype->is_union() || ttype->is_exception() ||
      ttype->is_paramlist()) {
    ctx.failure([&](auto& o) {
      o << "`" << type_string << "` is not a struct type."
        << " `@internal.InjectMetadataFields` can be only used with a struct type.";
    });
    return;
  }
  for (const auto& field : structured->fields()) {
    t_field_id injected_id;
    try {
      injected_id = cpp2::get_internal_injected_field_id(field.id());
    } catch (const std::exception& e) {
      ctx.failure([&](auto& o) { o << e.what(); });
      // Iterate all fields to find more failure.
      continue;
    }
    std::unique_ptr<t_field> cloned_field = field.clone_DO_NOT_USE();
    cloned_field->set_injected_id(injected_id);
    ctx.failure_if(
        !node.try_append_field(std::move(cloned_field)), [&](auto& o) {
          o << "Field id `" << field.id() << "` is already used in `"
            << node.name() << "`.";
        });
  }
}

void set_generated(diagnostic_context&, mutator_context&, t_named& node) {
  if (node.find_structured_annotation_or_null(kSetGenerated)) {
    node.set_generated();
  }
}

void normalize_return_type(
    diagnostic_context& ctx, mutator_context&, t_function& node) {
  auto& types = node.return_types();
  for (size_t i = 0; i < types.size(); ++i) {
    if (!types[i].resolve()) {
      ctx.failure(
          node, "Failed to resolve return type of `" + node.name() + "`.");
      return;
    }

    const auto* type = types[i]->get_true_type();
    if (auto* interaction = dynamic_cast<const t_interaction*>(type)) {
      if (i != 0) {
        ctx.failure([&](auto& o) {
          o << "Interactions are only allowed as the leftmost return type: "
            << type->get_full_name();
        });
      }

      // Old syntax treats returned interaction as response instead
      if (node.is_interaction_constructor()) {
        assert(types.size() == 1);
        node.set_response_pos(i);
        break;
      }
      node.set_returned_interaction_pos(i);
      if (types.size() == 1) {
        node.set_return_type(t_base_type::t_void());
        break;
      }
    } else if (auto* stream = dynamic_cast<const t_stream_response*>(type)) {
      if (i + 1 != types.size()) {
        ctx.failure([&](auto& o) {
          o << "Streams are only allowed as the rightmost return type: "
            << type->get_full_name();
        });
      }
      // TODO: move first response out of t_stream_response
      if (const auto& ret = node.return_type()) {
        const_cast<t_stream_response*>(stream)->set_first_response_type(ret);
      }
      node.set_response_pos(i);
    } else if (auto* sink = dynamic_cast<const t_sink*>(type)) {
      if (i + 1 != types.size()) {
        ctx.failure([&](auto& o) {
          o << "Sinks are only allowed as the rightmost return type: "
            << type->get_full_name();
        });
      }
      // TODO: move first response out of t_sink
      if (const auto& ret = node.return_type()) {
        const_cast<t_sink*>(sink)->set_first_response_type(ret);
      }
      node.set_response_pos(i);
    } else if (
        dynamic_cast<const t_service*>(type) ||
        dynamic_cast<const t_exception*>(type)) {
      ctx.failure([&](auto& o) {
        o << "Invalid return type: " << type->get_full_name();
      });
    } else {
      if (node.return_type()) {
        ctx.failure([&](auto& o) {
          o << "Too many return types: " << type->get_full_name();
        });
      }
      node.set_response_pos(i);
    }
  }
}

ast_mutators standard_mutators() {
  ast_mutators mutators;
  {
    auto& initial = mutators[standard_mutator_stage::initial];
    initial.add_interaction_visitor(
        &propagate_process_in_event_base_annotation);
    initial.add_function_visitor(&remove_param_list_field_qualifiers);
    initial.add_function_visitor(&normalize_return_type);
    initial.add_definition_visitor(&set_generated);
  }

  {
    auto& main = mutators[standard_mutator_stage::main];
    main.add_field_visitor(&mutate_terse_write_annotation_field);
    main.add_struct_visitor(&mutate_terse_write_annotation_struct);
    main.add_struct_visitor(&mutate_inject_metadata_fields);
  }
  add_patch_mutators(mutators);
  return mutators;
}

} // namespace compiler
} // namespace thrift
} // namespace apache
