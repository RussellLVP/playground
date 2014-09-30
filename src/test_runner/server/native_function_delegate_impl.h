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

#ifndef TEST_RUNNER_SERVER_NATIVE_FUNCTION_DELEGATE_IMPL_H_
#define TEST_RUNNER_SERVER_NATIVE_FUNCTION_DELEGATE_IMPL_H_

#include <map>
#include <string>

#include "server/testing/test_controller.h"

// Implements the native function delegate and overrides all the SA-MP functions we deem to be
// useful to have for testing. It emulates the behavior of the real server.
class NativeFunctionDelegateImpl : public TestController::NativeFunctionDelegate {
 public:
  NativeFunctionDelegateImpl();

  // TestController::NativeFunctionDelegate implementation.
  virtual int Invoke(const char* name, va_list arguments) override;

 private:
  std::map<std::string, void*> registered_natives_;

  // Implementations of the SA-MP native functions we override for the purposes of testing. They
  // should emulate behavior of the SA-MP natives as closely as possible.

  // a_samp.inc
  // -----------------------------------------------------------------------------------------------
  int GetWeather();
  int SetWeather(int weather_id);

 private:
  int current_weather_;
};

#endif  // TEST_RUNNER_SERVER_NATIVE_FUNCTION_IMPL_H_
