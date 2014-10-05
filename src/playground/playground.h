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

#ifndef PLAYGROUND_PLAYGROUND_H_
#define PLAYGROUND_PLAYGROUND_H_

#include "base/macros.h"
#include "playground/entities/player_manager.h"

class ServerInterface;

// The Playground class is the core object providing the Las Venturas Playground C++ game logic. It
// owns the different managers, receives critical events and talks to the individual features.
class Playground {
 public:
  explicit Playground(ServerInterface* server_interface);
  ~Playground();

  // Called when the server's main thread has finished its event loop.
  void ProcessTick();

  // Returns a references to the managers owned by this class.
  PlayerManager& player_manager() { return player_manager_; }

private:
  // Weak pointer which' lifetime is controlled by the plugin runtime.
  ServerInterface* server_interface_;

  // The entity managers owned by the server. Las Venturas Playground keeps track of entities by
  // itself, without relying on calling SA-MP natives for every bit of data.
  PlayerManager player_manager_;

  DISALLOW_COPY_AND_ASSIGN(Playground);
};

#endif  // PLAYGROUND_PLAYGROUND_H_
