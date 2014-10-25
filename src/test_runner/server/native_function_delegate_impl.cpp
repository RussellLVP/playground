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
#include "test_runner/server/entities/player_manager.h"
#include "test_runner/server/server_controller.h"

NativeFunctionDelegateImpl::NativeFunctionDelegateImpl(ServerController* server_controller)
    : server_controller_(server_controller),
      current_weather_(0) {
  ProvideNative("GetWeather", &NativeFunctionDelegateImpl::GetWeather);
  ProvideNative("SetWeather", &NativeFunctionDelegateImpl::SetWeather);
  ProvideNative("SendClientMessageToAll", &NativeFunctionDelegateImpl::SendClientMessageToAll);

  ProvideNative("SetPlayerPos", &NativeFunctionDelegateImpl::SetPlayerPos);
  ProvideNative("GetPlayerPos", &NativeFunctionDelegateImpl::GetPlayerPos);
  ProvideNative("SetPlayerInterior", &NativeFunctionDelegateImpl::SetPlayerInterior);
  ProvideNative("GetPlayerInterior", &NativeFunctionDelegateImpl::GetPlayerInterior);
  ProvideNative("SetPlayerHealth", &NativeFunctionDelegateImpl::SetPlayerHealth);
  ProvideNative("GetPlayerHealth", &NativeFunctionDelegateImpl::GetPlayerHealth);
  ProvideNative("SetPlayerArmour", &NativeFunctionDelegateImpl::SetPlayerArmour);
  ProvideNative("GetPlayerArmour", &NativeFunctionDelegateImpl::GetPlayerArmour);
  ProvideNative("GetPlayerMoney", &NativeFunctionDelegateImpl::GetPlayerMoney);
  ProvideNative("GivePlayerMoney", &NativeFunctionDelegateImpl::GivePlayerMoney);
  ProvideNative("GetPlayerName", &NativeFunctionDelegateImpl::GetPlayerName);
  ProvideNative("GetPlayerIp", &NativeFunctionDelegateImpl::GetPlayerIp);
  ProvideNative("SetPlayerVirtualWorld", &NativeFunctionDelegateImpl::SetPlayerVirtualWorld);
  ProvideNative("GetPlayerVirtualWorld", &NativeFunctionDelegateImpl::GetPlayerVirtualWorld);
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
  if (functor == registered_natives_.end()) {
    LOG(ERROR) << "The native " << name << " has not been overridden in the NativeFunctionDelegateImpl.";
    return 0;
  }

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

int NativeFunctionDelegateImpl::SendClientMessageToAll(int color, std::string* message) {
  return 0;
}

// -------------------------------------------------------------------------------------------------

#define GET_PLAYER_OR_RETURN(player, player_id) \
  Player* player = server_controller_->player_manager().Get(player_id); \
  if (player == nullptr) return 0;

int NativeFunctionDelegateImpl::SetPlayerPos(int player_id, double x, double y, double z) {
  GET_PLAYER_OR_RETURN(player, player_id);

  player->position = Vector3D(x, y, z);
  return 0;
}

int NativeFunctionDelegateImpl::GetPlayerPos(int player_id, double* x, double* y, double* z) {
  GET_PLAYER_OR_RETURN(player, player_id);
  CHECK(x && y && z);

  *x = player->position.x;
  *y = player->position.y;
  *z = player->position.z;
  return 1;
}

int NativeFunctionDelegateImpl::SetPlayerInterior(int player_id, int interior_id) {
  GET_PLAYER_OR_RETURN(player, player_id);

  player->interior_id = interior_id;
  return 0;
}

int NativeFunctionDelegateImpl::GetPlayerInterior(int player_id) {
  GET_PLAYER_OR_RETURN(player, player_id);

  return player->interior_id;
}

int NativeFunctionDelegateImpl::SetPlayerHealth(int player_id, double health) {
  GET_PLAYER_OR_RETURN(player, player_id);

  player->health = health;
  return 0;
}

int NativeFunctionDelegateImpl::GetPlayerHealth(int player_id, double* health) {
  GET_PLAYER_OR_RETURN(player, player_id);

  *health = player->health;
  return 1;
}

int NativeFunctionDelegateImpl::SetPlayerArmour(int player_id, double armour) {
  GET_PLAYER_OR_RETURN(player, player_id);

  player->armour = armour;
  return 0;
}

int NativeFunctionDelegateImpl::GetPlayerArmour(int player_id, double* armour) {
  GET_PLAYER_OR_RETURN(player, player_id);

  *armour = player->armour;
  return 1;
}

int NativeFunctionDelegateImpl::GetPlayerMoney(int player_id) {
  GET_PLAYER_OR_RETURN(player, player_id);

  return player->money;
}

int NativeFunctionDelegateImpl::GivePlayerMoney(int player_id, int money) {
  GET_PLAYER_OR_RETURN(player, player_id);

  player->money += money;
  return 1;
}

int NativeFunctionDelegateImpl::GetPlayerName(int player_id, std::string* name, int length) {
  GET_PLAYER_OR_RETURN(player, player_id);

  *name = player->nickname;
  return 1;
}

int NativeFunctionDelegateImpl::GetPlayerIp(int player_id, std::string* ip_address, int length) {
  GET_PLAYER_OR_RETURN(player, player_id);

  *ip_address = player->ip_address;
  return 1;
}

int NativeFunctionDelegateImpl::SetPlayerVirtualWorld(int player_id, int world_id) {
  GET_PLAYER_OR_RETURN(player, player_id);

  player->virtual_world = world_id;
  return 1;
}

int NativeFunctionDelegateImpl::GetPlayerVirtualWorld(int player_id) {
  GET_PLAYER_OR_RETURN(player, player_id);

  return player->virtual_world;
}
