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

#include <memory>

#include "base/macros.h"

class PlayerManager;
class ServerInterface;
class ServiceManager;

// The Playground class is the core object providing the Las Venturas Playground C++ game logic. It
// owns the different managers, receives critical events and talks to the individual features.
class Playground {
 public:
  explicit Playground(ServerInterface* server_interface);
  ~Playground();

  // Called when the server's main thread has finished its event loop.
  void ProcessTick();

  // Returns the service manager. This may be used to interact with the components and features that
  // are running as part of Las Venturas Playground.
  ServiceManager& service_manager() { return *service_manager_; }

  // Returns a references to the managers owned by this class.
  PlayerManager& player_manager() { return *player_manager_; }

private:
  // Weak pointer which' lifetime is controlled by the plugin runtime.
  ServerInterface* server_interface_;

  // The service manager owns all components and features running on the server.
  std::unique_ptr<ServiceManager> service_manager_;

  // The entity managers owned by the server. Las Venturas Playground keeps track of entities by
  // itself, without relying on calling SA-MP natives for every bit of data.
  std::unique_ptr<PlayerManager> player_manager_;

  DISALLOW_COPY_AND_ASSIGN(Playground);
};

#endif  // PLAYGROUND_PLAYGROUND_H_
