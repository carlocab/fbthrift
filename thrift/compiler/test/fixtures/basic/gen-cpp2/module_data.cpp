/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic/gen-cpp2/module_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

namespace apache {
namespace thrift {

const std::array<::test::fixtures::basic::MyEnum, 2> TEnumDataStorage<::test::fixtures::basic::MyEnum>::values = {{
  type::MyValue1,
  type::MyValue2,
}};
const std::array<folly::StringPiece, 2> TEnumDataStorage<::test::fixtures::basic::MyEnum>::names = {{
  "MyValue1",
  "MyValue2",
}};

const std::array<::test::fixtures::basic::MyUnion::Type, 4> TEnumDataStorage<::test::fixtures::basic::MyUnion::Type>::values = {{
  type::myEnum,
  type::myStruct,
  type::myDataItem,
  type::floatSet,
}};
const std::array<folly::StringPiece, 4> TEnumDataStorage<::test::fixtures::basic::MyUnion::Type>::names = {{
  "myEnum",
  "myStruct",
  "myDataItem",
  "floatSet",
}};

const std::array<folly::StringPiece, 0> TStructDataStorage<::test::fixtures::basic::MyDataItem>::fields_names = {{
}};
const std::array<int16_t, 0> TStructDataStorage<::test::fixtures::basic::MyDataItem>::fields_ids = {{
}};
const std::array<protocol::TType, 0> TStructDataStorage<::test::fixtures::basic::MyDataItem>::fields_types = {{
}};

const std::array<folly::StringPiece, 9> TStructDataStorage<::test::fixtures::basic::MyStruct>::fields_names = {{
  "MyIntField",
  "MyStringField",
  "MyDataField",
  "myEnum",
  "oneway",
  "readonly",
  "idempotent",
  "floatSet",
  "no_hack_codegen_field",
}};
const std::array<int16_t, 9> TStructDataStorage<::test::fixtures::basic::MyStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
}};
const std::array<protocol::TType, 9> TStructDataStorage<::test::fixtures::basic::MyStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
  TType::T_STRUCT,
  TType::T_I32,
  TType::T_BOOL,
  TType::T_BOOL,
  TType::T_BOOL,
  TType::T_SET,
  TType::T_STRING,
}};

const std::array<folly::StringPiece, 4> TStructDataStorage<::test::fixtures::basic::MyUnion>::fields_names = {{
  "myEnum",
  "myStruct",
  "myDataItem",
  "floatSet",
}};
const std::array<int16_t, 4> TStructDataStorage<::test::fixtures::basic::MyUnion>::fields_ids = {{
  1,
  2,
  3,
  4,
}};
const std::array<protocol::TType, 4> TStructDataStorage<::test::fixtures::basic::MyUnion>::fields_types = {{
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_SET,
}};

} // namespace thrift
} // namespace apache
