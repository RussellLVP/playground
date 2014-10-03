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

#ifndef TEST_RUNNER_SERVER_NATIVE_FUNCTION_DELEGATE_IMPL_INTERNAL_H_
#define TEST_RUNNER_SERVER_NATIVE_FUNCTION_DELEGATE_IMPL_INTERNAL_H_

#include <functional>
#include <stdarg.h>
#include <string>
#include <tuple>
#include <vector>

#include "base/logging.h"

class NativeFunctionDelegateImpl;

namespace internal {

template<class T, int... Is>
struct integer_sequence {};

template<class T, int N, int... Is>
struct make_integer_sequence : make_integer_sequence<T, N - 1, N - 1, Is...> {};

template<class T, int... Is>
struct make_integer_sequence<T, 0, Is...> : integer_sequence<T, Is...> {};

struct ArgumentValue {
  explicit ArgumentValue(int value)
      : type_(Integer) { primitive_.i = value; }
  explicit ArgumentValue(double value)
      : type_(Double) { primitive_.d = value; }
  explicit ArgumentValue(std::string* value)
      : type_(String) { primitive_.s = value; }

  template <typename T> static T Get(const ArgumentValue& value) { CHECK(false) << "Unrecognized argument type."; return T(); }

  template <> static int Get(const ArgumentValue& value) { return value.primitive_.i; }
  template <> static double Get(const ArgumentValue& value) { return value.primitive_.d; }
  template <> static std::string* Get(const ArgumentValue& value) { return value.primitive_.s; }

  enum Type { Integer, Double, String };
  Type type_;

  union {
    int i;
    double d;
    std::string* s;

  } primitive_;
};

template <typename... Arguments>
struct ArgumentForwarder {
  using tuple_t = std::tuple<Arguments...>;

 public:
  ArgumentForwarder(va_list argument_list)
      : argument_list_(argument_list) {}

  template <unsigned int Index>
  ArgumentValue ReadArgument() {
    using result_type = typename std::tuple_element<Index, tuple_t>::type;
    return ArgumentValue(va_arg(argument_list_, std::decay_t<result_type>));
  }

  template <unsigned int Index>
  typename std::tuple_element<Index, tuple_t>::type Apply(std::vector<internal::ArgumentValue>* arguments) const {
    CHECK(arguments->size() >= Index);

    using result_type = typename std::tuple_element<Index, tuple_t>::type;
    return ArgumentValue::Get<std::decay_t<result_type>>(arguments->at(Index));
  }

private:
  va_list argument_list_;
};

}  // namespace internal

class NativeFunctionBase {
 public:
  virtual ~NativeFunctionBase() {}
  virtual int Invoke(NativeFunctionDelegateImpl* instance, va_list arguments) const = 0;
};

template<typename... Arguments>
class NativeFunction : public NativeFunctionBase {
 typedef int(NativeFunctionDelegateImpl::*FunctionType)(Arguments...);

 public:
  NativeFunction(FunctionType method)
      : method_(method) {}

  virtual ~NativeFunction() override {}
  virtual int Invoke(NativeFunctionDelegateImpl* instance, va_list argument_list) const override {
    return InvokeImpl(instance, argument_list, internal::make_integer_sequence<unsigned int, sizeof...(Arguments)>());
  }

 private:
  template <unsigned int... Indices>
  int InvokeImpl(NativeFunctionDelegateImpl* instance, va_list argument_list, internal::integer_sequence<unsigned int, Indices...> sequence) const {
    internal::ArgumentForwarder<Arguments...> forwarder(argument_list);
    std::vector<internal::ArgumentValue> arguments{ forwarder.ReadArgument<Indices>()... };

    return (*instance.*method_)(forwarder.Apply<Indices>(&arguments)...);
  }

  FunctionType method_;
};

#endif  // TEST_RUNNER_SERVER_NATIVE_FUNCTION_DELEGATE_IMPL_INTERNAL_H_
