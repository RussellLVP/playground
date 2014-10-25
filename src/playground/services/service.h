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

#include "base/json/json_object.h"
#include "playground/services/service_macros.h"
#include "playground/services/service_registration.h"

class PlayerManager;

// A service is the base class of any component or feature in Las Venturas Playground, which allows
// services to conveniently access other internal systems. Services are owned by the ServiceManager.
class Service {
 public:
  virtual ~Service() {}

 protected:
  explicit Service(Playground* playground);

  // Returns the name of the current service. Must be implemented in each service, which will be
  // done automatically by the DEFINE_SERVICE() macro.
  virtual const char* service_name() const = 0;

  // Called when the service has been installed, and should be used to register the service with
  // event listeners and activate timers. This should not be done in the constructor, as it won't
  // be possible to create a weak pointer based on the service yet at that point.
  virtual void OnServiceInstalled() {}

  // Returns the configuration object specific to this server. May be empty it if wasn't defined.
  JsonObject configuration() const;

  PlayerManager& player_manager() const;

 private:
  // Weak reference to the Playground instance that owns this service.
  Playground* playground_;

  friend class ServiceManager;
};

#endif  // PLAYGROUND_SERVICES_SERVICE_H_
