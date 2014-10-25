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

#include "server/testing/server_test.h"

#include "base/logging.h"
#include "server/sdk/plugincommon.h"
#include "server/server_interface_impl.h"
#include "server/testing/test_controller_impl.h"

namespace {

// This is a deliberate layering violation. Server tests need to be able to initialize a completely
// new environment, which is why they should share the default initialization path. The relevant
// methods (exported as part of the SA-MP plugin) are defined in //playground.
PLUGIN_EXPORT bool PLUGIN_CALL Load(void** data);
PLUGIN_EXPORT void PLUGIN_CALL Unload();

// Data passed to the Load() function, which //server should be able to initialize itself with.
void* g_load_data[] = { nullptr, nullptr, nullptr, nullptr };

// Returns the test action delegate, which is provided by the test runner to allow us to interact
// with the embedding server environment.
TestController::TestActionDelegate& GetTestActionDelegate() {
  TestController::TestActionDelegate* action_delegate =
      TestControllerImpl::GetInstance()->test_action_delegate();
  CHECK(action_delegate) << "Interacting with the server required a test action delegate.";

  return *action_delegate;
}

}  // namespace

extern Playground* g_playground;
extern ServerInterfaceImpl* g_server_interface_impl;

ServerTest::~ServerTest() {}

int ServerTest::ConnectPlayer(const std::string& nickname, const std::string& ip_address) {
  return GetTestActionDelegate().ConnectPlayer(nickname, ip_address);
}

bool ServerTest::Say(int player_id, const std::string& message) {
  return GetTestActionDelegate().PlayerSay(player_id, message);
}

void ServerTest::DisconnectPlayer(int player_id) {
  GetTestActionDelegate().DisconnectPlayer(player_id);
}

Playground* ServerTest::playground() const {
  return g_playground;
}

void ServerTest::SetUp() {
  CHECK(!g_server_interface_impl);
  Load(g_load_data);

  // The ServerInterfaceImpl should now have been created.
  CHECK(g_server_interface_impl);
}

void ServerTest::TearDown() {
  CHECK(g_server_interface_impl);
  Unload();

  // The ServerInterfaceImpl should now have been released.
  CHECK(!g_server_interface_impl);
}
