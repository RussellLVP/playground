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

#include "base/logging.h"

NativeFunctionDelegateImpl::NativeFunctionDelegateImpl()
    : current_weather_(0) {
  ProvideNative("GetWeather", &NativeFunctionDelegateImpl::GetWeather);
  ProvideNative("SetWeather", &NativeFunctionDelegateImpl::SetWeather);
}

NativeFunctionDelegateImpl::~NativeFunctionDelegateImpl() {}

// -------------------------------------------------------------------------------------------------

template<typename ...Arguments>
void NativeFunctionDelegateImpl::ProvideNative(
    const std::string& name, int(NativeFunctionDelegateImpl::*method)(Arguments...)) {
  registered_natives_[name] = std::make_unique<NativeFunction<NativeFunctionDelegateImpl, Arguments...>>(method);
}

int NativeFunctionDelegateImpl::Invoke(const char* name, va_list arguments) {
  auto& functor = registered_natives_.find(name);
  if (functor == registered_natives_.end())
    return 0;

  return functor->second->Invoke(this, arguments);
}

// -------------------------------------------------------------------------------------------------

int NativeFunctionDelegateImpl::GetWeather() {
  return current_weather_;
}

int NativeFunctionDelegateImpl::SetWeather(int weather_id) {
  current_weather_ = weather_id;
  return 0;
}
