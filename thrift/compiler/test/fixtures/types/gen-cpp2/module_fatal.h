/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/reflection/reflection.h>

#include <fatal/type/list.h>
#include <fatal/type/pair.h>
#include <fatal/type/sequence.h>

#include "thrift/compiler/test/fixtures/types/gen-cpp2/module_types.h"
namespace apache { namespace thrift { namespace fixtures { namespace types {

namespace __fbthrift_refl {

struct __fbthrift_strings_module {
  using AllocatorAware = ::fatal::sequence<char, 'A', 'l', 'l', 'o', 'c', 'a', 't', 'o', 'r', 'A', 'w', 'a', 'r', 'e'>;
  using AllocatorAware2 = ::fatal::sequence<char, 'A', 'l', 'l', 'o', 'c', 'a', 't', 'o', 'r', 'A', 'w', 'a', 'r', 'e', '2'>;
  using AnnotatedTypes = ::fatal::sequence<char, 'A', 'n', 'n', 'o', 't', 'a', 't', 'e', 'd', 'T', 'y', 'p', 'e', 's'>;
  using ComplexNestedWithDefault = ::fatal::sequence<char, 'C', 'o', 'm', 'p', 'l', 'e', 'x', 'N', 'e', 's', 't', 'e', 'd', 'W', 'i', 't', 'h', 'D', 'e', 'f', 'a', 'u', 'l', 't'>;
  using ComplexString = ::fatal::sequence<char, 'C', 'o', 'm', 'p', 'l', 'e', 'x', 'S', 't', 'r', 'i', 'n', 'g'>;
  using ContainerStruct = ::fatal::sequence<char, 'C', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r', 'S', 't', 'r', 'u', 'c', 't'>;
  using CppTypeStruct = ::fatal::sequence<char, 'C', 'p', 'p', 'T', 'y', 'p', 'e', 'S', 't', 'r', 'u', 'c', 't'>;
  using ForwardUsageByRef = ::fatal::sequence<char, 'F', 'o', 'r', 'w', 'a', 'r', 'd', 'U', 's', 'a', 'g', 'e', 'B', 'y', 'R', 'e', 'f'>;
  using ForwardUsageRoot = ::fatal::sequence<char, 'F', 'o', 'r', 'w', 'a', 'r', 'd', 'U', 's', 'a', 'g', 'e', 'R', 'o', 'o', 't'>;
  using ForwardUsageStruct = ::fatal::sequence<char, 'F', 'o', 'r', 'w', 'a', 'r', 'd', 'U', 's', 'a', 'g', 'e', 'S', 't', 'r', 'u', 'c', 't'>;
  using MinPadding = ::fatal::sequence<char, 'M', 'i', 'n', 'P', 'a', 'd', 'd', 'i', 'n', 'g'>;
  using MyBinaryField = ::fatal::sequence<char, 'M', 'y', 'B', 'i', 'n', 'a', 'r', 'y', 'F', 'i', 'e', 'l', 'd'>;
  using MyBinaryField2 = ::fatal::sequence<char, 'M', 'y', 'B', 'i', 'n', 'a', 'r', 'y', 'F', 'i', 'e', 'l', 'd', '2'>;
  using MyBinaryField3 = ::fatal::sequence<char, 'M', 'y', 'B', 'i', 'n', 'a', 'r', 'y', 'F', 'i', 'e', 'l', 'd', '3'>;
  using MyBinaryListField4 = ::fatal::sequence<char, 'M', 'y', 'B', 'i', 'n', 'a', 'r', 'y', 'L', 'i', 's', 't', 'F', 'i', 'e', 'l', 'd', '4'>;
  using MyBoolField = ::fatal::sequence<char, 'M', 'y', 'B', 'o', 'o', 'l', 'F', 'i', 'e', 'l', 'd'>;
  using MyDataItem = ::fatal::sequence<char, 'M', 'y', 'D', 'a', 't', 'a', 'I', 't', 'e', 'm'>;
  using MyEnumA = ::fatal::sequence<char, 'M', 'y', 'E', 'n', 'u', 'm', 'A'>;
  using MyForwardRefEnum = ::fatal::sequence<char, 'M', 'y', 'F', 'o', 'r', 'w', 'a', 'r', 'd', 'R', 'e', 'f', 'E', 'n', 'u', 'm'>;
  using MyIntField = ::fatal::sequence<char, 'M', 'y', 'I', 'n', 't', 'F', 'i', 'e', 'l', 'd'>;
  using MyMapEnumAndInt = ::fatal::sequence<char, 'M', 'y', 'M', 'a', 'p', 'E', 'n', 'u', 'm', 'A', 'n', 'd', 'I', 'n', 't'>;
  using MyStringField = ::fatal::sequence<char, 'M', 'y', 'S', 't', 'r', 'i', 'n', 'g', 'F', 'i', 'e', 'l', 'd'>;
  using MyStringField2 = ::fatal::sequence<char, 'M', 'y', 'S', 't', 'r', 'i', 'n', 'g', 'F', 'i', 'e', 'l', 'd', '2'>;
  using MyStruct = ::fatal::sequence<char, 'M', 'y', 'S', 't', 'r', 'u', 'c', 't'>;
  using MyStructWithForwardRefEnum = ::fatal::sequence<char, 'M', 'y', 'S', 't', 'r', 'u', 'c', 't', 'W', 'i', 't', 'h', 'F', 'o', 'r', 'w', 'a', 'r', 'd', 'R', 'e', 'f', 'E', 'n', 'u', 'm'>;
  using NONZERO = ::fatal::sequence<char, 'N', 'O', 'N', 'Z', 'E', 'R', 'O'>;
  using NoExceptMoveUnion = ::fatal::sequence<char, 'N', 'o', 'E', 'x', 'c', 'e', 'p', 't', 'M', 'o', 'v', 'e', 'U', 'n', 'i', 'o', 'n'>;
  using NoexceptMoveComplexStruct = ::fatal::sequence<char, 'N', 'o', 'e', 'x', 'c', 'e', 'p', 't', 'M', 'o', 'v', 'e', 'C', 'o', 'm', 'p', 'l', 'e', 'x', 'S', 't', 'r', 'u', 'c', 't'>;
  using NoexceptMoveEmpty = ::fatal::sequence<char, 'N', 'o', 'e', 'x', 'c', 'e', 'p', 't', 'M', 'o', 'v', 'e', 'E', 'm', 'p', 't', 'y'>;
  using NoexceptMoveSimpleStruct = ::fatal::sequence<char, 'N', 'o', 'e', 'x', 'c', 'e', 'p', 't', 'M', 'o', 'v', 'e', 'S', 'i', 'm', 'p', 'l', 'e', 'S', 't', 'r', 'u', 'c', 't'>;
  using Renaming = ::fatal::sequence<char, 'R', 'e', 'n', 'a', 'm', 'i', 'n', 'g'>;
  using SomeService = ::fatal::sequence<char, 'S', 'o', 'm', 'e', 'S', 'e', 'r', 'v', 'i', 'c', 'e'>;
  using TrivialNestedWithDefault = ::fatal::sequence<char, 'T', 'r', 'i', 'v', 'i', 'a', 'l', 'N', 'e', 's', 't', 'e', 'd', 'W', 'i', 't', 'h', 'D', 'e', 'f', 'a', 'u', 'l', 't'>;
  using TrivialNumeric = ::fatal::sequence<char, 'T', 'r', 'i', 'v', 'i', 'a', 'l', 'N', 'u', 'm', 'e', 'r', 'i', 'c'>;
  using Type = ::fatal::sequence<char, 'T', 'y', 'p', 'e'>;
  using VirtualStruct = ::fatal::sequence<char, 'V', 'i', 'r', 't', 'u', 'a', 'l', 'S', 't', 'r', 'u', 'c', 't'>;
  using ZERO = ::fatal::sequence<char, 'Z', 'E', 'R', 'O'>;
  using a = ::fatal::sequence<char, 'a'>;
  using aa_list = ::fatal::sequence<char, 'a', 'a', '_', 'l', 'i', 's', 't'>;
  using aa_map = ::fatal::sequence<char, 'a', 'a', '_', 'm', 'a', 'p'>;
  using aa_set = ::fatal::sequence<char, 'a', 'a', '_', 's', 'e', 't'>;
  using aa_string = ::fatal::sequence<char, 'a', 'a', '_', 's', 't', 'r', 'i', 'n', 'g'>;
  using apache__thrift__fixtures__types = ::fatal::sequence<char, 'a', 'p', 'a', 'c', 'h', 'e', ':', ':', 't', 'h', 'r', 'i', 'f', 't', ':', ':', 'f', 'i', 'x', 't', 'u', 'r', 'e', 's', ':', ':', 't', 'y', 'p', 'e', 's'>;
  using b = ::fatal::sequence<char, 'b'>;
  using bar = ::fatal::sequence<char, 'b', 'a', 'r'>;
  using big = ::fatal::sequence<char, 'b', 'i', 'g'>;
  using biggish = ::fatal::sequence<char, 'b', 'i', 'g', 'g', 'i', 's', 'h'>;
  using binary_field = ::fatal::sequence<char, 'b', 'i', 'n', 'a', 'r', 'y', '_', 'f', 'i', 'e', 'l', 'd'>;
  using binary_keyed_map = ::fatal::sequence<char, 'b', 'i', 'n', 'a', 'r', 'y', '_', 'k', 'e', 'y', 'e', 'd', '_', 'm', 'a', 'p'>;
  using boolField = ::fatal::sequence<char, 'b', 'o', 'o', 'l', 'F', 'i', 'e', 'l', 'd'>;
  using bounce_map = ::fatal::sequence<char, 'b', 'o', 'u', 'n', 'c', 'e', '_', 'm', 'a', 'p'>;
  using cpp = ::fatal::sequence<char, 'c', 'p', 'p'>;
  using cpp2 = ::fatal::sequence<char, 'c', 'p', 'p', '2'>;
  using cpp2_noncomparable = ::fatal::sequence<char, 'c', 'p', 'p', '2', '.', 'n', 'o', 'n', 'c', 'o', 'm', 'p', 'a', 'r', 'a', 'b', 'l', 'e'>;
  using cpp_allocator = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'a', 'l', 'l', 'o', 'c', 'a', 't', 'o', 'r'>;
  using cpp_declare_bitwise_ops = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'd', 'e', 'c', 'l', 'a', 'r', 'e', '_', 'b', 'i', 't', 'w', 'i', 's', 'e', '_', 'o', 'p', 's'>;
  using cpp_declare_equal_to = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'd', 'e', 'c', 'l', 'a', 'r', 'e', '_', 'e', 'q', 'u', 'a', 'l', '_', 't', 'o'>;
  using cpp_declare_hash = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'd', 'e', 'c', 'l', 'a', 'r', 'e', '_', 'h', 'a', 's', 'h'>;
  using cpp_deprecated_enum_unscoped = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'd', 'e', 'p', 'r', 'e', 'c', 'a', 't', 'e', 'd', '_', 'e', 'n', 'u', 'm', '_', 'u', 'n', 's', 'c', 'o', 'p', 'e', 'd'>;
  using cpp_minimize_padding = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'm', 'i', 'n', 'i', 'm', 'i', 'z', 'e', '_', 'p', 'a', 'd', 'd', 'i', 'n', 'g'>;
  using cpp_noexcept_move = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'n', 'o', 'e', 'x', 'c', 'e', 'p', 't', '_', 'm', 'o', 'v', 'e'>;
  using cpp_virtual = ::fatal::sequence<char, 'c', 'p', 'p', '.', 'v', 'i', 'r', 't', 'u', 'a', 'l'>;
  using data = ::fatal::sequence<char, 'd', 'a', 't', 'a'>;
  using decorated_struct = ::fatal::sequence<char, 'd', 'e', 'c', 'o', 'r', 'a', 't', 'e', 'd', '_', 's', 't', 'r', 'u', 'c', 't'>;
  using field = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd'>;
  using fieldA = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'A'>;
  using fieldB = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'B'>;
  using fieldC = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'C'>;
  using fieldD = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'D'>;
  using fieldE = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'E'>;
  using fieldF = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'F'>;
  using fieldG = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'G'>;
  using fieldH = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'H'>;
  using foo = ::fatal::sequence<char, 'f', 'o', 'o'>;
  using has_bitwise_ops = ::fatal::sequence<char, 'h', 'a', 's', '_', 'b', 'i', 't', 'w', 'i', 's', 'e', '_', 'o', 'p', 's'>;
  using hello = ::fatal::sequence<char, 'h', 'e', 'l', 'l', 'o'>;
  using i32_field = ::fatal::sequence<char, 'i', '3', '2', '_', 'f', 'i', 'e', 'l', 'd'>;
  using is_unscoped = ::fatal::sequence<char, 'i', 's', '_', 'u', 'n', 's', 'c', 'o', 'p', 'e', 'd'>;
  using list_field = ::fatal::sequence<char, 'l', 'i', 's', 't', '_', 'f', 'i', 'e', 'l', 'd'>;
  using m = ::fatal::sequence<char, 'm'>;
  using majorVer = ::fatal::sequence<char, 'm', 'a', 'j', 'o', 'r', 'V', 'e', 'r'>;
  using medium = ::fatal::sequence<char, 'm', 'e', 'd', 'i', 'u', 'm'>;
  using module = ::fatal::sequence<char, 'm', 'o', 'd', 'u', 'l', 'e'>;
  using n = ::fatal::sequence<char, 'n'>;
  using none = ::fatal::sequence<char, 'n', 'o', 'n', 'e'>;
  using not_a_container = ::fatal::sequence<char, 'n', 'o', 't', '_', 'a', '_', 'c', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r'>;
  using one = ::fatal::sequence<char, 'o', 'n', 'e'>;
  using r = ::fatal::sequence<char, 'r'>;
  using small = ::fatal::sequence<char, 's', 'm', 'a', 'l', 'l'>;
  using string_field = ::fatal::sequence<char, 's', 't', 'r', 'i', 'n', 'g', '_', 'f', 'i', 'e', 'l', 'd'>;
  using three = ::fatal::sequence<char, 't', 'h', 'r', 'e', 'e'>;
  using tiny = ::fatal::sequence<char, 't', 'i', 'n', 'y'>;
  using two = ::fatal::sequence<char, 't', 'w', 'o'>;
  using world = ::fatal::sequence<char, 'w', 'o', 'r', 'l', 'd'>;
  using z = ::fatal::sequence<char, 'z'>;
  using zero = ::fatal::sequence<char, 'z', 'e', 'r', 'o'>;
};

} // __fbthrift_refl

class module_tags {
  using __fbthrift_strings = __fbthrift_refl::__fbthrift_strings_module;
  struct __fbthrift_languages {
    using cpp = __fbthrift_strings::cpp;
    using cpp2 = __fbthrift_strings::cpp2;
  };
  struct __fbthrift_enums {
    using has_bitwise_ops = __fbthrift_strings::has_bitwise_ops;
    using is_unscoped = __fbthrift_strings::is_unscoped;
    using MyForwardRefEnum = __fbthrift_strings::MyForwardRefEnum;
    using MyEnumA = __fbthrift_strings::MyEnumA;
  };
  struct __fbthrift_unions {
    using NoExceptMoveUnion = __fbthrift_strings::NoExceptMoveUnion;
  };
  struct __fbthrift_structs {
    using decorated_struct = __fbthrift_strings::decorated_struct;
    using ContainerStruct = __fbthrift_strings::ContainerStruct;
    using CppTypeStruct = __fbthrift_strings::CppTypeStruct;
    using VirtualStruct = __fbthrift_strings::VirtualStruct;
    using MyStructWithForwardRefEnum = __fbthrift_strings::MyStructWithForwardRefEnum;
    using TrivialNumeric = __fbthrift_strings::TrivialNumeric;
    using TrivialNestedWithDefault = __fbthrift_strings::TrivialNestedWithDefault;
    using ComplexString = __fbthrift_strings::ComplexString;
    using ComplexNestedWithDefault = __fbthrift_strings::ComplexNestedWithDefault;
    using MinPadding = __fbthrift_strings::MinPadding;
    using MyStruct = __fbthrift_strings::MyStruct;
    using MyDataItem = __fbthrift_strings::MyDataItem;
    using Renaming = __fbthrift_strings::Renaming;
    using AnnotatedTypes = __fbthrift_strings::AnnotatedTypes;
    using ForwardUsageRoot = __fbthrift_strings::ForwardUsageRoot;
    using ForwardUsageStruct = __fbthrift_strings::ForwardUsageStruct;
    using ForwardUsageByRef = __fbthrift_strings::ForwardUsageByRef;
    using NoexceptMoveEmpty = __fbthrift_strings::NoexceptMoveEmpty;
    using NoexceptMoveSimpleStruct = __fbthrift_strings::NoexceptMoveSimpleStruct;
    using NoexceptMoveComplexStruct = __fbthrift_strings::NoexceptMoveComplexStruct;
    using AllocatorAware = __fbthrift_strings::AllocatorAware;
    using AllocatorAware2 = __fbthrift_strings::AllocatorAware2;
  };
  struct __fbthrift_constants {
  };
  struct __fbthrift_services {
    using SomeService = __fbthrift_strings::SomeService;
  };
 public:
  struct module {};

  using strings = __fbthrift_strings;
  using languages = __fbthrift_languages;
  using enums = __fbthrift_enums;
  using unions = __fbthrift_unions;
  using structs = __fbthrift_structs;
  using constants = __fbthrift_constants;
  using services = __fbthrift_services;
};

THRIFT_REGISTER_REFLECTION_METADATA(
  module_tags::module,
  __fbthrift_refl::__fbthrift_strings_module::module,
  // languages
  ::fatal::list<
    ::fatal::pair<__fbthrift_refl::__fbthrift_strings_module::cpp, __fbthrift_refl::__fbthrift_strings_module::apache__thrift__fixtures__types>,
    ::fatal::pair<__fbthrift_refl::__fbthrift_strings_module::cpp2, __fbthrift_refl::__fbthrift_strings_module::apache__thrift__fixtures__types>
  >,
  // enums
  ::fatal::list<
    ::fatal::pair<has_bitwise_ops, __fbthrift_refl::__fbthrift_strings_module::has_bitwise_ops>,
    ::fatal::pair<is_unscoped, __fbthrift_refl::__fbthrift_strings_module::is_unscoped>,
    ::fatal::pair<MyForwardRefEnum, __fbthrift_refl::__fbthrift_strings_module::MyForwardRefEnum>,
    ::fatal::pair<MyEnumA, __fbthrift_refl::__fbthrift_strings_module::MyEnumA>
  >,
  // unions
  ::fatal::list<
    ::fatal::pair<NoExceptMoveUnion, __fbthrift_refl::__fbthrift_strings_module::NoExceptMoveUnion>
  >,
  // structs
  ::fatal::list<
    ::fatal::pair<decorated_struct, __fbthrift_refl::__fbthrift_strings_module::decorated_struct>,
    ::fatal::pair<ContainerStruct, __fbthrift_refl::__fbthrift_strings_module::ContainerStruct>,
    ::fatal::pair<CppTypeStruct, __fbthrift_refl::__fbthrift_strings_module::CppTypeStruct>,
    ::fatal::pair<VirtualStruct, __fbthrift_refl::__fbthrift_strings_module::VirtualStruct>,
    ::fatal::pair<MyStructWithForwardRefEnum, __fbthrift_refl::__fbthrift_strings_module::MyStructWithForwardRefEnum>,
    ::fatal::pair<TrivialNumeric, __fbthrift_refl::__fbthrift_strings_module::TrivialNumeric>,
    ::fatal::pair<TrivialNestedWithDefault, __fbthrift_refl::__fbthrift_strings_module::TrivialNestedWithDefault>,
    ::fatal::pair<ComplexString, __fbthrift_refl::__fbthrift_strings_module::ComplexString>,
    ::fatal::pair<ComplexNestedWithDefault, __fbthrift_refl::__fbthrift_strings_module::ComplexNestedWithDefault>,
    ::fatal::pair<MinPadding, __fbthrift_refl::__fbthrift_strings_module::MinPadding>,
    ::fatal::pair<MyStruct, __fbthrift_refl::__fbthrift_strings_module::MyStruct>,
    ::fatal::pair<MyDataItem, __fbthrift_refl::__fbthrift_strings_module::MyDataItem>,
    ::fatal::pair<Renaming, __fbthrift_refl::__fbthrift_strings_module::Renaming>,
    ::fatal::pair<AnnotatedTypes, __fbthrift_refl::__fbthrift_strings_module::AnnotatedTypes>,
    ::fatal::pair<ForwardUsageRoot, __fbthrift_refl::__fbthrift_strings_module::ForwardUsageRoot>,
    ::fatal::pair<ForwardUsageStruct, __fbthrift_refl::__fbthrift_strings_module::ForwardUsageStruct>,
    ::fatal::pair<ForwardUsageByRef, __fbthrift_refl::__fbthrift_strings_module::ForwardUsageByRef>,
    ::fatal::pair<NoexceptMoveEmpty, __fbthrift_refl::__fbthrift_strings_module::NoexceptMoveEmpty>,
    ::fatal::pair<NoexceptMoveSimpleStruct, __fbthrift_refl::__fbthrift_strings_module::NoexceptMoveSimpleStruct>,
    ::fatal::pair<NoexceptMoveComplexStruct, __fbthrift_refl::__fbthrift_strings_module::NoexceptMoveComplexStruct>,
    ::fatal::pair<AllocatorAware, __fbthrift_refl::__fbthrift_strings_module::AllocatorAware>,
    ::fatal::pair<AllocatorAware2, __fbthrift_refl::__fbthrift_strings_module::AllocatorAware2>
  >,
  // constants
  ::fatal::list<
  >,
  // services
  ::fatal::list<
    __fbthrift_refl::__fbthrift_strings_module::SomeService
  >
);

}}}} // apache::thrift::fixtures::types
#include "thrift/compiler/test/fixtures/types/gen-cpp2/module_fatal_types.h"
