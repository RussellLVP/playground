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

#include "playground/playground.h"
#include "playground/services/service_macros.h"

template <class ServiceImpl> struct ServiceRegistrationImpl;

// Base class using which services can be identified.
class ServiceBase {
 public:
  virtual ~ServiceBase() {}
};

// A service is the base class of any component or feature in Las Venturas Playground. It provides
// the necessary tools to enable dependency management, mock injection, event propagation and object
// lifetime management. Services are owned by the ServiceManager.
template <class ServiceImpl>
class Service : public ServiceBase {
 protected:
  explicit Service(Playground* playground)
      : playground_(playground) {}
  virtual ~Service() {}

  // Returns the player manager owned by the Playground instance.
  PlayerManager& GetPlayerManager() const { return playground_->player_manager(); }

 private:
  // Initializes a new instance of the Service, based on |playground| as the runtime environment for
  // Las Venturas Playground. Must only be called by the ServiceRegistration for this service.
  static ServiceImpl* Create(Playground* playground) {
    return new ServiceImpl(playground);
  }

  Playground* playground_;

  friend struct ServiceRegistrationImpl<ServiceImpl>;
};

#endif  // PLAYGROUND_SERVICES_SERVICE_H_
