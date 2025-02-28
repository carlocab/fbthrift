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

#include <thrift/compiler/gen/cpp/type_resolver.h>

#include <stdexcept>

#include <fmt/core.h>
#include <thrift/compiler/ast/t_list.h>
#include <thrift/compiler/ast/t_map.h>
#include <thrift/compiler/ast/t_node.h>
#include <thrift/compiler/ast/t_set.h>
#include <thrift/compiler/ast/t_struct.h>
#include <thrift/compiler/ast/t_typedef.h>

namespace apache {
namespace thrift {
namespace compiler {
namespace gen {
namespace cpp {

const std::string& type_resolver::get_type_name(
    const t_field& field, const t_structured& parent) {
  const t_type& type = *field.type();

  // TODO (dokwon): Support composing adapters.
  if (const std::string* adapter_on_field =
          find_structured_adapter_annotation(field)) {
    return detail::get_or_gen(field_type_cache_, &field, [&]() {
      return gen_field_type(field.id(), type, parent, adapter_on_field);
    });
  }

  // If @cpp.Adapter is used on typedef of the field, use the typedef name.
  if (const auto* typedf = dynamic_cast<const t_typedef*>(&type)) {
    if (find_structured_adapter_annotation(*typedf)) {
      return namespaces_.get_namespaced_name(*typedf);
    }
  }

  return get_type_name(type);
}

const std::string& type_resolver::get_type_name(const t_typedef& node) {
  // When `t_placeholder_typedef` is used, `t_type_ref::deref` will
  // automatically dereference `t_placeholder_typedef` as well. Since
  // unstructured annotations are stored in `t_placeholder_typedef`, we can't
  // use `t_type_ref::deref`.
  const t_type* type = node.type().get_type();
  if (type == nullptr) {
    throw std::runtime_error("t_type_ref has no type.");
  }
  if (const std::string* adapter = find_structured_adapter_annotation(node)) {
    return detail::get_or_gen(
        type_cache_, &node, [&]() { return gen_type(*type, adapter); });
  }
  return get_type_name(*type);
}

const std::string& type_resolver::get_storage_type_name(
    const t_field& field, const t_structured& parent) {
  auto ref_type = find_ref_type(field);
  if (ref_type == reference_type::none) {
    // The storage type is just the type name.
    return get_type_name(field, parent);
  }
  return detail::get_or_gen(storage_type_cache_, {&field, ref_type}, [&]() {
    return gen_storage_type(ref_type, field, parent);
  });
}

const std::string* type_resolver::find_first_adapter(const t_type& node) {
  if (const std::string* adapter = find_structured_adapter_annotation(node)) {
    return adapter;
  }
  return t_typedef::get_first_annotation_or_null(&node, {"cpp.adapter"});
}

const std::string* type_resolver::find_first_adapter(const t_field& field) {
  if (const std::string* adapter = find_structured_adapter_annotation(field)) {
    return adapter;
  }
  if (const std::string* adapter = find_first_adapter(*field.type())) {
    return adapter;
  }
  return nullptr;
}

bool type_resolver::can_resolve_to_scalar(const t_type& node) {
  return node.get_true_type()->is_scalar() || find_first_adapter(node) ||
      find_first_type(node);
}

const std::string& type_resolver::default_template(t_container::type ctype) {
  switch (ctype) {
    case t_container::type::t_list: {
      static const auto& kValue = *new std::string("::std::vector");
      return kValue;
    }
    case t_container::type::t_set: {
      static const auto& kValue = *new std::string("::std::set");
      return kValue;
    }
    case t_container::type::t_map: {
      static const auto& kValue = *new std::string("::std::map");
      return kValue;
    }
  }
  throw std::runtime_error(
      "unknown container type: " + std::to_string(static_cast<int>(ctype)));
}

const std::string& type_resolver::default_type(t_base_type::type btype) {
  switch (btype) {
    case t_base_type::type::t_void: {
      static const auto& kValue = *new std::string("void");
      return kValue;
    }
    case t_base_type::type::t_bool: {
      static const auto& kValue = *new std::string("bool");
      return kValue;
    }
    case t_base_type::type::t_byte: {
      static const auto& kValue = *new std::string("::std::int8_t");
      return kValue;
    }
    case t_base_type::type::t_i16: {
      static const auto& kValue = *new std::string("::std::int16_t");
      return kValue;
    }
    case t_base_type::type::t_i32: {
      static const auto& kValue = *new std::string("::std::int32_t");
      return kValue;
    }
    case t_base_type::type::t_i64: {
      static const auto& kValue = *new std::string("::std::int64_t");
      return kValue;
    }
    case t_base_type::type::t_float: {
      static const auto& kValue = *new std::string("float");
      return kValue;
    }
    case t_base_type::type::t_double: {
      static const auto& kValue = *new std::string("double");
      return kValue;
    }
    case t_base_type::type::t_string:
    case t_base_type::type::t_binary: {
      static const auto& kValue = *new std::string("::std::string");
      return kValue;
    }
  }
  throw std::runtime_error(
      "unknown base type: " + std::to_string(static_cast<int>(btype)));
}

std::string type_resolver::gen_type(const t_type& node) {
  if (const auto* type = find_type(node)) {
    // Use the override.
    return *type;
  }
  // Use the unmodified name.
  return gen_raw_type_name(node, &type_resolver::get_type_name);
}

std::string type_resolver::gen_standard_type(const t_type& node) {
  if (const auto* type = find_type(node)) {
    // Return the override.
    return *type;
  }

  if (const auto* ttypedef = dynamic_cast<const t_typedef*>(&node)) {
    // Traverse the typedef.
    // TODO(afuller): Always traverse the adapter. There are some cpp.type and
    // cpp.template annotations that rely on the namespacing of the typedef to
    // avoid namespacing issues with the annotation itself. To avoid breaking
    // these cases we are only traversing the typedef when the presences of an
    // adapter requires we do so. However, we should update all annotations to
    // using fully qualified names, then always traverse here.
    if (find_first_adapter(node) != nullptr) {
      return get_standard_type_name(*ttypedef->get_type());
    }
  }

  return gen_raw_type_name(node, &type_resolver::get_standard_type_name);
}

std::string type_resolver::gen_storage_type(
    reference_type& ref_type,
    const t_field& field,
    const t_structured& parent) {
  const std::string& type_name = get_type_name(field, parent);
  const std::string* cpp_template =
      field.find_annotation_or_null("cpp.template");
  switch (ref_type) {
    case reference_type::unique:
      if (cpp_template != nullptr) {
        return detail::gen_template_type(*cpp_template, {type_name});
      } else {
        return detail::gen_template_type("::std::unique_ptr", {type_name});
      }
    case reference_type::shared_mutable:
      return detail::gen_template_type("::std::shared_ptr", {type_name});
    case reference_type::shared_const:
      return detail::gen_template_type(
          "::std::shared_ptr", {"const " + type_name});
    case reference_type::boxed:
      return detail::gen_template_type(
          "::apache::thrift::detail::boxed_value_ptr", {type_name});
    default:
      throw std::runtime_error("unknown cpp ref_type");
  }
}

std::string type_resolver::gen_raw_type_name(
    const t_type& node, type_resolve_fn resolve_fn) {
  // Base types have fixed type mappings.
  if (const auto* tbase_type = dynamic_cast<const t_base_type*>(&node)) {
    return default_type(tbase_type->base_type());
  }

  // Containers have fixed template mappings.
  if (const auto* tcontainer = dynamic_cast<const t_container*>(&node)) {
    return gen_container_type(*tcontainer, resolve_fn);
  }

  // Streaming types have special handling.
  if (const auto* tstream_res = dynamic_cast<const t_stream_response*>(&node)) {
    return gen_stream_resp_type(*tstream_res, resolve_fn);
  }
  if (const auto* tsink = dynamic_cast<const t_sink*>(&node)) {
    return gen_sink_type(*tsink, resolve_fn);
  }

  // For everything else, just use namespaced name.
  return namespaces_.get_namespaced_name(node);
}

std::string type_resolver::gen_container_type(
    const t_container& node, type_resolve_fn resolve_fn) {
  const auto* val = find_template(node);
  const auto& template_name =
      val ? *val : default_template(node.container_type());

  switch (node.container_type()) {
    case t_container::type::t_list:
      return detail::gen_template_type(
          template_name,
          {resolve(
              resolve_fn, *static_cast<const t_list&>(node).get_elem_type())});
    case t_container::type::t_set:
      return detail::gen_template_type(
          template_name,
          {resolve(
              resolve_fn, *static_cast<const t_set&>(node).get_elem_type())});
    case t_container::type::t_map: {
      const auto& tmap = static_cast<const t_map&>(node);
      return detail::gen_template_type(
          template_name,
          {resolve(resolve_fn, *tmap.get_key_type()),
           resolve(resolve_fn, *tmap.get_val_type())});
    }
  }
  throw std::runtime_error(
      "unknown container type: " +
      std::to_string(static_cast<int>(node.container_type())));
}

std::string type_resolver::gen_stream_resp_type(
    const t_stream_response& node, type_resolve_fn resolve_fn) {
  if (!node.first_response_type().empty()) {
    return detail::gen_template_type(
        "::apache::thrift::ResponseAndServerStream",
        {resolve(resolve_fn, *node.get_first_response_type()),
         resolve(resolve_fn, *node.get_elem_type())});
  }
  return detail::gen_template_type(
      "::apache::thrift::ServerStream",
      {resolve(resolve_fn, *node.get_elem_type())});
}

std::string type_resolver::gen_sink_type(
    const t_sink& node, type_resolve_fn resolve_fn) {
  if (!node.first_response_type().empty()) {
    return detail::gen_template_type(
        "::apache::thrift::ResponseAndSinkConsumer",
        {resolve(resolve_fn, *node.get_first_response_type()),
         resolve(resolve_fn, *node.get_sink_type()),
         resolve(resolve_fn, *node.get_final_response_type())});
  }
  return detail::gen_template_type(
      "::apache::thrift::SinkConsumer",
      {resolve(resolve_fn, *node.get_sink_type()),
       resolve(resolve_fn, *node.get_final_response_type())});
}

std::string type_resolver::gen_adapted_type(
    const std::string* adapter, const std::string& standard_type) {
  return adapter == nullptr ? standard_type
                            : detail::gen_template_type(
                                  "::apache::thrift::adapt_detail::adapted_t",
                                  {*adapter, standard_type});
}
std::string type_resolver::gen_adapted_type(
    const std::string* adapter,
    int16_t field_id,
    const std::string& standard_type,
    const t_structured& parent) {
  return adapter == nullptr
      ? standard_type
      : detail::gen_template_type(
            "::apache::thrift::adapt_detail::adapted_field_t",
            {
                *adapter,
                std::to_string(field_id),
                standard_type,
                namespace_resolver::get_cpp_name(parent),
            });
}

// TODO(ytj): Support type::adapted, and cpp.template
std::string type_resolver::gen_type_tag(const t_type& type) {
  auto tag = gen_thrift_type_tag(type);
  if (const auto* cpp_type = find_first_type(type)) {
    tag =
        fmt::format("::apache::thrift::type::cpp_type<{}, {}>", *cpp_type, tag);
  }
  if (const auto* cpp_adapter = find_first_adapter(type)) {
    tag = fmt::format(
        "::apache::thrift::type::adapted<{}, {}>", *cpp_adapter, tag);
  }
  return tag;
}

std::string type_resolver::gen_type_tag(const t_field& field) {
  std::string type_tag = gen_type_tag(*field.type());
  if (const std::string* adapter = find_structured_adapter_annotation(field)) {
    return fmt::format(
        "::apache::thrift::type::field_t<::apache::thrift::FieldId{{{}}}, ::apache::thrift::type::adapted<{}, {}>>",
        field.id(),
        *adapter,
        type_tag);
  }
  return fmt::format(
      "::apache::thrift::type::field_t<::apache::thrift::FieldId{{{}}}, {}>",
      field.id(),
      type_tag);
}

std::string type_resolver::gen_thrift_type_tag(const t_type& original_type) {
  static const std::string ns = "::apache::thrift::type::";
  auto const& type = *original_type.get_true_type();
  if (type.is_void()) {
    return ns + "void_t";
  } else if (type.is_bool()) {
    return ns + "bool_t";
  } else if (type.is_byte()) {
    return ns + "byte_t";
  } else if (type.is_i16()) {
    return ns + "i16_t";
  } else if (type.is_i32()) {
    return ns + "i32_t";
  } else if (type.is_i64()) {
    return ns + "i64_t";
  } else if (type.is_float()) {
    return ns + "float_t";
  } else if (type.is_double()) {
    return ns + "double_t";
  } else if (type.is_enum()) {
    return ns + "enum_t<" + get_standard_type_name(type) + ">";
  } else if (type.is_string()) {
    return ns + "string_t";
  } else if (type.is_binary()) {
    return ns + "binary_t";
  } else if (type.is_list()) {
    auto& list = dynamic_cast<t_list const&>(type);
    auto& elem = *list.get_elem_type();
    auto elem_tag = gen_type_tag(elem);
    return ns + "list<" + elem_tag + ">";
  } else if (type.is_set()) {
    auto& set = dynamic_cast<t_set const&>(type);
    auto& elem = *set.get_elem_type();
    auto elem_tag = gen_type_tag(elem);
    return ns + "set<" + elem_tag + ">";
  } else if (type.is_map()) {
    auto& map = dynamic_cast<t_map const&>(type);
    auto& key = *map.get_key_type();
    auto& val = *map.get_val_type();
    auto key_tag = gen_type_tag(key);
    auto val_tag = gen_type_tag(val);
    return ns + "map<" + key_tag + ", " + val_tag + ">";
  } else if (type.is_union()) {
    return ns + "union_t<" + get_standard_type_name(type) + ">";
  } else if (type.is_struct()) {
    return ns + "struct_t<" + get_standard_type_name(type) + ">";
  } else if (type.is_exception()) {
    return ns + "exception_t<" + get_standard_type_name(type) + ">";
  } else {
    throw std::runtime_error("unknown type for: " + type.get_full_name());
  }
}

} // namespace cpp
} // namespace gen
} // namespace compiler
} // namespace thrift
} // namespace apache
