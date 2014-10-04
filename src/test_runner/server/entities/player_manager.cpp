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

#include "test_runner/server/entities/player_manager.h"

Player::Player(const std::string& nickname, const std::string& ip_address)
    : nickname(nickname),
      ip_address(ip_address) {}

// -------------------------------------------------------------------------------------------------

int PlayerManager::Connect(const std::string& nickname, const std::string& ip_address) {
  int player_id = 0;
  while (players_.find(player_id) != players_.end())
    ++player_id;

  players_[player_id] = std::make_unique<Player>(nickname, ip_address);
  return player_id;
}

Player* PlayerManager::Get(int player_id) {
  auto& iterator = players_.find(player_id);
  if (iterator == players_.end())
    return nullptr;

  return iterator->second.get();
}

void PlayerManager::Disconnect(int player_id) {
  players_.erase(player_id);
}
