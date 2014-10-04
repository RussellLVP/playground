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

#include "server/testing/test_controller_impl.h"

#include "base/logging.h"
#include "gtest/gtest.h"

namespace {

// The TestControllerImpl instance is owned by the embedder, but we hold on to a weak reference
// allowing code in //server to interact with the controller.
TestControllerImpl* g_test_controller_instance_ = nullptr;

}  // namespace

// -------------------------------------------------------------------------------------------------

// Static. Declared in /server/testing/test_controller.h.
TestController* TestController::Create() {
  return new TestControllerImpl();
}

// -------------------------------------------------------------------------------------------------

TestControllerImpl::TestControllerImpl()
    : native_function_delegate_(nullptr) {
  CHECK(!g_test_controller_instance_) << "There may only be a single TestController at any given time.";
  g_test_controller_instance_ = this;
}

TestControllerImpl::~TestControllerImpl() {
  g_test_controller_instance_ = nullptr;
}

// static
TestControllerImpl* TestControllerImpl::GetInstance() {
  return g_test_controller_instance_;
}

void TestControllerImpl::SetNativeFunctionDelegate(NativeFunctionDelegate* delegate) {
  native_function_delegate_ = delegate;
}

int TestControllerImpl::RunTests(int* argc, char** argv) {
  ::testing::InitGoogleTest(argc, argv);

  return RUN_ALL_TESTS();
}
