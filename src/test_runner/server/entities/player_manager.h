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

#ifndef TEST_RUNNER_SERVER_ENTITIES_PLAYER_MANAGER_H_
#define TEST_RUNNER_SERVER_ENTITIES_PLAYER_MANAGER_H_

#include <map>
#include <memory>
#include <string>

#include "base/vector3d.h"

// Represents the mocked information available for any individual player.
struct Player {
  Player(const std::string& nickname, const std::string& ip_address);

  std::string nickname;
  std::string ip_address;

  Vector3D position;
  int interior_id;
  double health;
  double armour;
  int virtual_world;
};

// When running tests, the player manager is the authorative source of information about which
// players are connected to Las Venturas Playground.
class PlayerManager {
 public:
  // Inserts a new player named |nickname| in the manager, using the next available Id.
  int Connect(const std::string& nickname, const std::string& ip_address);

  // Returns the player who is connected using Id |player_id|. May return a nullptr.
  Player* Get(int player_id);

  // Removes the player with Id |player_id| from the manager.
  void Disconnect(int player_id);

 private:
  std::map<int, std::unique_ptr<Player>> players_;
};

#endif  // TEST_RUNNER_SERVER_ENTITIES_PLAYER_MANAGER_H_
