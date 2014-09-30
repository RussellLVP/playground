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

#ifndef SERVER_TESTING_TEST_CONTROLLER_IMPL_H_
#define SERVER_TESTING_TEST_CONTROLLER_IMPL_H_

#include "server/testing/test_controller.h"

class TestControllerImpl final : public TestController {
 public:
  TestControllerImpl();
  ~TestControllerImpl();

  // Returns the active instance of the TestControllerImpl. This is what code in //server should use
  // when functionality may be influenced by the external test-runner.
  static TestControllerImpl* GetInstance();

  // Returns the native function delegate to which Pawn native calls should be forwarded.
  NativeFunctionDelegate* native_function_delegate() const {
    return native_function_delegate_;
  }

  // TestController implementation.
  virtual void SetNativeFunctionDelegate(NativeFunctionDelegate* delegate) override;

 private:
  NativeFunctionDelegate* native_function_delegate_;
};

#endif  // SERVER_TESTING_TEST_CONTROLLER_IMPL_H_
