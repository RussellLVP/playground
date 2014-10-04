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

#include <memory>
#include <stdio.h>

#include "base/logging.h"
#include "gtest/gtest.h"
#include "test_runner/samp_plugin.h"
#include "test_runner/server/server_controller.h"
#include "server/testing/test_controller.h"

#if defined(WINDOWS)
#define MODULE_NAME "playground.dll"
#else // !defined(WINDOWS)
#define MODULE_NAME "playground.so"
#endif

int main(int argc, char** argv) {
  SampPlugin plugin;
  if (!plugin.LoadPlugin(MODULE_NAME))
    return 1;

  std::unique_ptr<TestController> test_controller(plugin.CreateTestController());
  CHECK(test_controller);

  ServerController server_controller(test_controller.get());

  ::testing::InitGoogleTest(&argc, argv);

  int return_value = RUN_ALL_TESTS();
  if (return_value == 0 /** no errors **/)
    return_value = test_controller->RunTests(&argc, argv);

  return return_value;
}
