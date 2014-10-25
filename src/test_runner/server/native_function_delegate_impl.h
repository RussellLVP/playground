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
#include <memory>
#include <string>

#include "server/testing/test_controller.h"
#include "test_runner/server/native_function_delegate_impl_internal.h"

class ServerController;

// Implements the native function delegate and overrides all the SA-MP functions we deem to be
// useful to have for testing. It emulates the behavior of the real server.
class NativeFunctionDelegateImpl : public TestController::NativeFunctionDelegate {
 public:
  NativeFunctionDelegateImpl(ServerController* controller);
  virtual ~NativeFunctionDelegateImpl();

  // TestController::NativeFunctionDelegate implementation.
  virtual int Invoke(const char* name, va_list arguments) override;

 private:
  // Provides the native function |name| which will be handled by |method|.
  template<typename ...Arguments>
  void ProvideNative(const std::string& name, int(NativeFunctionDelegateImpl::*method)(Arguments...));

  // Implementations of the SA-MP native functions we override for the purposes of testing. They
  // should emulate behavior of the SA-MP natives as closely as possible.

  // a_samp.inc
  // -----------------------------------------------------------------------------------------------
  int GetWeather();
  int SetWeather(int weather_id);
  int SendClientMessageToAll(int color, std::string* message);

  // a_players.inc
  int SetPlayerPos(int player_id, double x, double y, double z);
  int GetPlayerPos(int player_id, double* x, double* y, double* z);
  int SetPlayerInterior(int player_id, int interior_id);
  int GetPlayerInterior(int player_id);
  int SetPlayerHealth(int player_id, double health);
  int GetPlayerHealth(int player_id, double* health);
  int SetPlayerArmour(int player_id, double armour);
  int GetPlayerArmour(int player_id, double* armour);
  int GetPlayerMoney(int player_id);
  int GivePlayerMoney(int player_id, int money);
  int GetPlayerName(int player_id, std::string* name, int length);
  int GetPlayerIp(int player_id, std::string* ip_address, int length);
  int SetPlayerVirtualWorld(int player_id, int world_id);
  int GetPlayerVirtualWorld(int player_id);

 private:
  ServerController* server_controller_;
  std::map<std::string, std::unique_ptr<NativeFunctionBase<NativeFunctionDelegateImpl>>>
      registered_natives_;

  int current_weather_;
};

#endif  // TEST_RUNNER_SERVER_NATIVE_FUNCTION_IMPL_H_
