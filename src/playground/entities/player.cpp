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

int Player::id() const {
  return player_id_;
}
