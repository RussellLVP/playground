/**
 * Copyright (c) 2006-2014 Las Venturas Playground
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "test_runner/server/native_function_delegate_impl.h"
#include "test_runner/server/native_function_delegate_impl_internal.h"

#include "base/logging.h"
#include "gtest/gtest.h"

namespace {

class NativeFunctionDelegateInternalTest : public ::testing::Test {
 protected:
  NativeFunctionDelegateInternalTest() {
    ProvideNative("ReadInteger", &NativeFunctionDelegateInternalTest::ReadInteger);
    ProvideNative("WriteInteger", &NativeFunctionDelegateInternalTest::WriteInteger);
    ProvideNative("ReadFloat", &NativeFunctionDelegateInternalTest::ReadFloat);
    ProvideNative("WriteFloat", &NativeFunctionDelegateInternalTest::WriteFloat);
    ProvideNative("ReverseString", &NativeFunctionDelegateInternalTest::ReverseString);
    ProvideNative("ArgumentOrder", &NativeFunctionDelegateInternalTest::ArgumentOrder);
    ProvideNative("MixedArguments", &NativeFunctionDelegateInternalTest::MixedArguments);
  }

  virtual ~NativeFunctionDelegateInternalTest() {}

  // Calls a provided native with name |method| and the expected arguments.
  int Call(const char* method, ...) {
    const auto& native_function = registered_natives_.find(method);
    CHECK(native_function != registered_natives_.end());

    va_list arguments;
    va_start(arguments, method);

    return native_function->second->Invoke(this, arguments);
  }

  // Resets all internal values back to their defaults. Will be called before each individual test.
  virtual void SetUp() override {
    int_value_ = 0;
    float_value_ = 0.0;
  }

 private:
  int ReadInteger() { return int_value_; }
  int WriteInteger(int value) { int_value_ = value; return 0; }

  int ReadFloat() { return *(int*) &float_value_; }
  int WriteFloat(double value) { float_value_ = static_cast<float>(value); return 0; }

  int ReverseString(std::string* value) {
    std::reverse(value->begin(), value->end());
    return 0;
  }

  int ArgumentOrder(int a, int b, int c, int d, int e) {
    return 10000 * a + 1000 * b + 100 * c + 10 * d + e;
  }

  int MixedArguments(int a, double b, std::string* c) {
    return 1000 * a + 100 * b + c->at(0);
  }

 private:
  template<typename ...Arguments>
  void ProvideNative(const std::string& name, int(NativeFunctionDelegateInternalTest::*method)(Arguments...)) {
    registered_natives_[name] =
        std::make_unique<NativeFunction<NativeFunctionDelegateInternalTest, Arguments...>>(method);
  }

  std::map<std::string,
           std::unique_ptr<NativeFunctionBase<NativeFunctionDelegateInternalTest>>>
               registered_natives_;

  int int_value_;
  float float_value_;
};

}  // namespace

TEST_F(NativeFunctionDelegateInternalTest, ReadWriteInteger) {
  ASSERT_EQ(0, Call("ReadInteger"));
  Call("WriteInteger", 123456789);
  ASSERT_EQ(123456789, Call("ReadInteger"));
}

TEST_F(NativeFunctionDelegateInternalTest, ReadWriteFloat) {
  int value = Call("ReadFloat");
  float float_value = *(float*) &value;

  ASSERT_FLOAT_EQ(0.0, float_value);

  Call("WriteFloat", 1234567.8f);

  value = Call("ReadFloat");
  float_value = *(float*) &value;

  ASSERT_FLOAT_EQ(1234567.8, float_value);
}

TEST_F(NativeFunctionDelegateInternalTest, ReverseString) {
  std::string text = "Playground";
  Call("ReverseString", &text);

  ASSERT_EQ("dnuorgyalP", text);
}

TEST_F(NativeFunctionDelegateInternalTest, ArgumentOrder) {
  ASSERT_EQ(12345, Call("ArgumentOrder", 1, 2, 3, 4, 5));
}

TEST_F(NativeFunctionDelegateInternalTest, MixedArguments) {
  std::string text = "P";
  ASSERT_EQ(1280, Call("MixedArguments", 1, 2.0f, &text));
}
