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

class NativeFunctionDelegateImpl;

namespace internal {

template<class T, int... Is>
struct integer_sequence {};

template<class T, int N, int... Is>
struct make_integer_sequence : make_integer_sequence<T, N - 1, N - 1, Is...> {};

template<class T, int... Is>
struct make_integer_sequence<T, 0, Is...> : integer_sequence<T, Is...> {};

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
  virtual int Invoke(NativeFunctionDelegateImpl* instance, va_list arguments) const override {
    return InvokeImpl(instance, arguments, internal::make_integer_sequence<unsigned int, sizeof...(Arguments)>());
  }

 private:
  template <unsigned int... Indices>
  int InvokeImpl(NativeFunctionDelegateImpl* instance, va_list arguments, internal::integer_sequence<unsigned int, Indices...>) const {
    return 0;
  }

  FunctionType method_;
};

#endif  // TEST_RUNNER_SERVER_NATIVE_FUNCTION_DELEGATE_IMPL_INTERNAL_H_
