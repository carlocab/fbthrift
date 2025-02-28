/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once

#include <functional>
#include <folly/Range.h>

#include <thrift/lib/py3/enums.h>
#include "thrift/annotation/gen-cpp2/thrift_data.h"
#include "thrift/annotation/gen-cpp2/thrift_types.h"
#include "thrift/annotation/gen-cpp2/thrift_metadata.h"
namespace thrift {
namespace py3 {



template<>
void reset_field<::facebook::thrift::annotation::RequiresBackwardCompatibility>(
    ::facebook::thrift::annotation::RequiresBackwardCompatibility& obj, uint16_t index) {
  switch (index) {
    case 0:
      obj.field_name_ref().copy_from(default_inst<::facebook::thrift::annotation::RequiresBackwardCompatibility>().field_name_ref());
      return;
  }
}

template<>
void reset_field<::facebook::thrift::annotation::Beta>(
    ::facebook::thrift::annotation::Beta& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::Experimental>(
    ::facebook::thrift::annotation::Experimental& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::Deprecated>(
    ::facebook::thrift::annotation::Deprecated& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::TerseWrite>(
    ::facebook::thrift::annotation::TerseWrite& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::Box>(
    ::facebook::thrift::annotation::Box& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::Mixin>(
    ::facebook::thrift::annotation::Mixin& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::SerializeInFieldIdOrder>(
    ::facebook::thrift::annotation::SerializeInFieldIdOrder& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::NoLegacyAPIs>(
    ::facebook::thrift::annotation::NoLegacyAPIs& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
void reset_field<::facebook::thrift::annotation::v1>(
    ::facebook::thrift::annotation::v1& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::RequiresBackwardCompatibility>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::Beta>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::Experimental>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::Deprecated>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::TerseWrite>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::Box>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::Mixin>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::SerializeInFieldIdOrder>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::NoLegacyAPIs>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::facebook::thrift::annotation::v1>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}
} // namespace py3
} // namespace thrift
