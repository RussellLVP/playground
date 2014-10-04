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

#ifndef SERVER_TESTING_TEST_CONTROLLER_H_
#define SERVER_TESTING_TEST_CONTROLLER_H_

#include <stdarg.h>

// The test controller allows the laucher to drive parts of the Playground plugin, making the entire
// gamemode testable with either scenario-tests or smaller unit-tests.
class TestController {
 public:
  // Creates a new implementation of the TestController class. The caller takes ownership of the
  // new instance. This method is implemented in test_controller_impl.cpp.
  static TestController* Create();

  virtual ~TestController() {}

  // Can be injected using SetNativeFunctionDelegate to forward all Pawn native function invocations
  // to the given method, instead of dispatching them on the AMX runtime. When registered, we will
  // never hit AMX runtime in NativeFunctionManager::Invoke.
  class NativeFunctionDelegate {
   public:
    virtual int Invoke(const char* name, va_list arguments) = 0;
  };

  // Registers a delegate to handle the native function invocations.
  virtual void SetNativeFunctionDelegate(NativeFunctionDelegate* delegate) = 0;

  // Runs all the tests which have been defined in the Playground module.
  virtual int RunTests(int* argc, char** argv) = 0;
};

#endif  // SERVER_TESTING_TEST_CONTROLLER_H_
