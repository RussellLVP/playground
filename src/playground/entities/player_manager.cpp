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

#include "playground/entities/player_manager.h"

#include <stdio.h>

#include "base/logging.h"
#include "playground/entities/player.h"

PlayerManager::PlayerManager() {}

PlayerManager::~PlayerManager() {}

Player* PlayerManager::Get(const std::string& name) {
  for (auto& player : players_) {
    if (name == player.second->name())
      return player.second.get();
  }

  return nullptr;
}

Player* PlayerManager::Get(int player_id) {
  auto& iterator = players_.find(player_id);
  if (iterator == players_.end())
    return nullptr;

  return iterator->second.get();
}

int PlayerManager::size() const {
  return players_.size();
}

void PlayerManager::OnPlayerConnect(int player_id) {
  if (Get(player_id) != nullptr) {
    LOG(ERROR) << "The player with Id " << player_id << " has already connected to the server.";
    return;
  }

  players_[player_id] = std::make_unique<Player>(player_id);
}

void PlayerManager::OnPlayerDisconnect(int player_id, int reason) {
  if (Get(player_id) == nullptr) {
    LOG(ERROR) << "The player with Id " << player_id << " is not connected to the server.";
    return;
  }

  players_.erase(player_id);
}
