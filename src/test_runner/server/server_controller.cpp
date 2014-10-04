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

#include "test_runner/server/server_controller.h"

#include "server/bindings/event_listener.h"

ServerController::ServerController(TestController* test_controller)
    : test_controller_(test_controller),
      native_function_delegate_(this) {
  test_controller_->SetNativeFunctionDelegate(&native_function_delegate_);
  test_controller_->SetTestActionDelegate(this);
}

ServerController::~ServerController() {
  test_controller_->SetNativeFunctionDelegate(nullptr);
  test_controller_->SetTestActionDelegate(nullptr);
}

int ServerController::ConnectPlayer(const std::string& nickname, const std::string& ip_address) {
  int player_id = player_manager_.Connect(nickname, ip_address);

  GetEventListener().OnPlayerConnect(player_id);
  return player_id;
}

void ServerController::DisconnectPlayer(int player_id) {
  GetEventListener().OnPlayerDisconnect(player_id, 0);
  player_manager_.Disconnect(player_id);
}

samp::EventListener& ServerController::GetEventListener() const {
  samp::EventListener* event_listener = test_controller_->GetEventListener();
  CHECK(event_listener) << "The test runner requires an event listener to be provided.";

  return *event_listener;
}
