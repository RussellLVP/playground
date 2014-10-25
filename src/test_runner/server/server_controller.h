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

#ifndef TEST_RUNNER_SERVER_SERVER_CONTROLLER_H_
#define TEST_RUNNER_SERVER_SERVER_CONTROLLER_H_

#include "server/testing/test_controller.h"
#include "test_runner/server/entities/player_manager.h"
#include "test_runner/server/native_function_delegate_impl.h"

class ServerController : public TestController::TestActionDelegate {
 public:
  ServerController(TestController* test_controller);
  virtual ~ServerController();

  // Returns the mocked player manager owned by this server controller.
  PlayerManager& player_manager() { return player_manager_; }

  // TestController::TestActionDelegate implementation.
  virtual int ConnectPlayer(const std::string& nickname, const std::string& ip_address) override;
  virtual bool PlayerSay(int player_id, const std::string& message) override;
  virtual void DisconnectPlayer(int player_id) override;

 private:
  // Returns the active EventListener for the test controller.
  samp::EventListener& GetEventListener() const;

  TestController* test_controller_;

  NativeFunctionDelegateImpl native_function_delegate_;

  PlayerManager player_manager_;
};

#endif  // TEST_RUNNER_SERVER_SERVER_CONTROLLER_H_
