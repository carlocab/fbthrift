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

#include <thrift/test/gen-cpp2/test_constants.h>
#include <thrift/test/gen-cpp2/test_types.h>

#include <folly/portability/GTest.h>

using namespace apache::thrift::test;

TEST(constants, examples) {
  EXPECT_EQ(enum1::field0, test_constants::e_1_);
  EXPECT_EQ(enum1::field0, test_constants::e_1());
  EXPECT_EQ(enum1::field2, test_constants::e_2_);
  EXPECT_EQ(enum1::field2, test_constants::e_2());

  EXPECT_EQ(72, test_constants::i_1_);
  EXPECT_EQ(72, test_constants::i_1());
  EXPECT_EQ(99, test_constants::i_2_);
  EXPECT_EQ(99, test_constants::i_2());

  EXPECT_EQ(std::string(), test_constants::str_e_);
  EXPECT_EQ(std::string(), test_constants::str_e());
  EXPECT_EQ(std::string("hello"), test_constants::str_1_);
  EXPECT_EQ(std::string("hello"), test_constants::str_1());
  EXPECT_EQ(std::string("world"), test_constants::str_2_);
  EXPECT_EQ(std::string("world"), test_constants::str_2());
  EXPECT_EQ(std::string("'"), test_constants::str_3());
  EXPECT_EQ(std::string("\"foo\""), test_constants::str_4());
  EXPECT_EQ(std::string("line 1\nline 2\n"), test_constants::str_5());

  EXPECT_TRUE(test_constants::l_e().empty());
  EXPECT_EQ((std::vector<std::int32_t>{23, 42, 56}), test_constants::l_1());
  EXPECT_EQ(
      (std::vector<std::string>{"foo", "bar", "baz"}), test_constants::l_2());

  EXPECT_TRUE(test_constants::s_e().empty());
  EXPECT_EQ((std::set<std::int32_t>{23, 42, 56}), test_constants::s_1());
  EXPECT_EQ(
      (std::set<std::string>{"foo", "bar", "baz"}), test_constants::s_2());

  EXPECT_TRUE(test_constants::m_e().empty());
  EXPECT_EQ(
      (std::map<std::int32_t, std::int32_t>{{23, 97}, {42, 37}, {56, 11}}),
      test_constants::m_1());
  EXPECT_EQ(
      (std::map<std::string, std::string>{{"foo", "bar"}, {"baz", "gaz"}}),
      test_constants::m_2());
  EXPECT_EQ(
      (std::map<std::string, std::int32_t>{
          {"'", 39}, {"\"", 34}, {"\\", 92}, {"a", 97}}),
      test_constants::m_3());

  EXPECT_EQ(struct1(), test_constants::pod_0());

  struct1 pod1;
  pod1.a_ref() = 10;
  pod1.b_ref() = "foo";

  auto const& pod_1 = test_constants::pod_1();
  EXPECT_TRUE(pod_1.a_ref().is_set());
  EXPECT_TRUE(pod_1.b_ref().is_set());
  EXPECT_EQ(pod1, pod_1);

  struct2 pod2;
  pod2.a_ref() = 98;
  pod2.b_ref() = "gaz";
  auto& pod2_c = pod2.c_ref().emplace(struct1());
  pod2_c.a_ref() = 12;
  pod2_c.b_ref() = "bar";
  pod2.d_ref() = std::vector<std::int32_t>{11, 22, 33};

  auto const& pod_2 = test_constants::pod_2();
  EXPECT_TRUE(pod_2.a_ref().is_set());
  EXPECT_TRUE(pod_2.b_ref().is_set());
  EXPECT_TRUE(pod_2.c_ref().is_set());
  EXPECT_TRUE(pod_2.d_ref().is_set());
  EXPECT_TRUE(pod_2.c_ref()->a_ref().is_set());
  EXPECT_TRUE(pod_2.c_ref()->b_ref().is_set());
  EXPECT_EQ(pod2, pod_2);

  auto const& pod_3 = test_constants::pod_3();
  EXPECT_TRUE(pod_3.a_ref().is_set());
  EXPECT_TRUE(pod_3.b_ref().is_set());
  EXPECT_TRUE(pod_3.c_ref().is_set());
  EXPECT_TRUE(pod_3.c_ref()->a_ref().is_set());
  EXPECT_FALSE(pod_3.c_ref()->b_ref().is_set());
  EXPECT_TRUE(pod_3.c_ref()->c_ref().is_set());
  EXPECT_FALSE(pod_3.c_ref()->d_ref().is_set());
  EXPECT_FALSE(pod_3.c_ref()->c_ref()->a_ref().is_set());
  EXPECT_TRUE(pod_3.c_ref()->c_ref()->b_ref().is_set());

  EXPECT_EQ(union1::Type::i, test_constants::u_1_1().getType());
  EXPECT_EQ(97, test_constants::u_1_1().get_i());

  EXPECT_EQ(union1::Type::d, test_constants::u_1_2().getType());
  EXPECT_EQ(5.6, test_constants::u_1_2().get_d());

  EXPECT_EQ(union1::Type::__EMPTY__, test_constants::u_1_3().getType());

  EXPECT_EQ(union2::Type::i, test_constants::u_2_1().getType());
  EXPECT_EQ(51, test_constants::u_2_1().get_i());

  EXPECT_EQ(union2::Type::d, test_constants::u_2_2().getType());
  EXPECT_EQ(6.7, test_constants::u_2_2().get_d());

  EXPECT_EQ(union2::Type::s, test_constants::u_2_3().getType());
  EXPECT_EQ(8, test_constants::u_2_3().get_s().get_a());
  EXPECT_EQ("abacabb", test_constants::u_2_3().get_s().get_b());

  EXPECT_EQ(union2::Type::u, test_constants::u_2_4().getType());
  EXPECT_EQ(union1::Type::i, test_constants::u_2_4().get_u().getType());
  EXPECT_EQ(43, test_constants::u_2_4().get_u().get_i());

  EXPECT_EQ(union2::Type::u, test_constants::u_2_5().getType());
  EXPECT_EQ(union1::Type::d, test_constants::u_2_5().get_u().getType());
  EXPECT_EQ(9.8, test_constants::u_2_5().get_u().get_d());

  EXPECT_EQ(union2::Type::u, test_constants::u_2_6().getType());
  EXPECT_EQ(union1::Type::__EMPTY__, test_constants::u_2_6().get_u().getType());

  EXPECT_EQ(test_constants::maxIntDec(), 9223372036854775807);

  EXPECT_EQ(test_constants::maxIntOct(), 0777777777777777777777);
  EXPECT_EQ(test_constants::maxIntHex(), 0x7FFFFFFFFFFFFFFF);
  EXPECT_EQ(test_constants::maxDub(), 1.79769313486231e+308);
  EXPECT_EQ(test_constants::minDub(), 2.2250738585072e-308);
  EXPECT_EQ(test_constants::minSDub(), 4.9406564584124654e-324);

  EXPECT_EQ(test_constants::maxPIntDec(), +9223372036854775807);
  EXPECT_EQ(test_constants::maxPDub(), +1.79769313486231e+308);
  EXPECT_EQ(test_constants::minPDub(), +2.2250738585072e-308);
  EXPECT_EQ(test_constants::minPSDub(), +4.9406564584124654e-324);

  EXPECT_EQ(test_constants::maxNDub(), -1.79769313486231e+308);
  EXPECT_EQ(test_constants::minNDub(), -2.2250738585072e-308);
  EXPECT_EQ(test_constants::minNSDub(), -4.9406564584124654e-324);
}
