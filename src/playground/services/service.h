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

#ifndef PLAYGROUND_SERVICES_SERVICE_H_
#define PLAYGROUND_SERVICES_SERVICE_H_

#include <memory>

#include "playground/playground.h"
#include "playground/services/service_macros.h"
#include "playground/services/service_registration.h"

// A service is the base class of any component or feature in Las Venturas Playground, which allows
// services to conveniently access other internal systems. Services are owned by the ServiceManager.
class Service {
 public:
  virtual ~Service() {}

 protected:
  explicit Service(Playground* playground)
      : playground_(playground) {}

  // Returns the player manager owned by the Playground instance.
  PlayerManager& GetPlayerManager() const { return playground_->player_manager(); }

 private:
  // Weak reference to the Playground instance that owns this service.
  Playground* playground_;
};

#endif  // PLAYGROUND_SERVICES_SERVICE_H_
