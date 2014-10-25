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

#include "playground/entities/player.h"

#include "base/logging.h"
#include "base/vector3d.h"
#include "server/bindings/players.h"
#include "server/bindings/samp.h"

Player::Player(int player_id)
    : player_id_(player_id) {
  samp::GetPlayerName(player_id, name_, samp::MAX_PLAYER_NAME);
  samp::GetPlayerIp(player_id, ip_address_, 16);
}

Player::~Player() {}

const std::string& Player::name() const {
  return name_;
}

const std::string& Player::ip_address() const {
  return ip_address_;
}

double Player::GetHealth() const {
  double health = 0.0;
  samp::GetPlayerHealth(player_id_, &health);
  return health;
}

void Player::SetHealth(double health) {
  samp::SetPlayerHealth(player_id_, health);
}

double Player::GetArmour() const {
  double armour = 0.0;
  samp::GetPlayerArmour(player_id_, &armour);
  return armour;
}

void Player::SetArmour(double armour) {
  samp::SetPlayerArmour(player_id_, armour);
}

int Player::GetMoney() const {
  return samp::GetPlayerMoney(player_id_);
}

void Player::GiveMoney(int money) {
  samp::GivePlayerMoney(player_id_, money);
}

void Player::SetMoney(int money) {
  GiveMoney(money - GetMoney());
}

int Player::id() const {
  return player_id_;
}

void Player::GetPosition(Vector3D* position) const {
  CHECK(position) << "A position vector must be supplied.";
  samp::GetPlayerPos(player_id_, &position->x, &position->y, &position->z);
}

void Player::SetPosition(const Vector3D& position) {
  samp::SetPlayerPos(player_id_, position.x, position.y, position.z);
}

int Player::GetInteriorId() const {
  return samp::GetPlayerInterior(player_id_);
}

void Player::SetInteriorId(int interior_id) {
  samp::SetPlayerInterior(player_id_, interior_id);
}

int Player::GetVirtualWorldId() const {
  return samp::GetPlayerVirtualWorld(player_id_);
}

void Player::SetVirtualWorldId(int virtual_world_id) {
  samp::SetPlayerVirtualWorld(player_id_, virtual_world_id);
}
