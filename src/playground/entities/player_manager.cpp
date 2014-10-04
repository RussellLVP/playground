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

PlayerManager::PlayerManager() {}

PlayerManager::~PlayerManager() {}

Player* PlayerManager::Get(const std::string& name) {
  return nullptr;
}

Player* PlayerManager::Get(int player_id) {
  return nullptr;
}

int PlayerManager::GetCount() const {
  return 0;
}

void PlayerManager::OnPlayerConnect(int player_id) {
  LOG(INFO) << "Player " << player_id << " has connected.";
}

void PlayerManager::OnPlayerDisconnect(int player_id, int reason) {
  LOG(INFO) << "Player " << player_id << " has connected.";
}
