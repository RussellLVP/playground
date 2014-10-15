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

#ifndef PLAYGROUND_SERVICES_SERVICE_MANAGER_H_
#define PLAYGROUND_SERVICES_SERVICE_MANAGER_H_

#include <memory>
#include <unordered_map>

#include "playground/services/service.h"

class Playground;
struct ServiceRegistration;

// The service manager owns all services (components and features) within Las Venturas Playground.
// It enables cross-service communication, ensures their initialization order and will ensure that
// we end up with the appropriate instance of a service (e.g. the mock for testing).
class ServiceManager {
 public:
  ServiceManager();

  // Registers a service called |name| provided by |registration|.
  static void RegisterService(const char* name, ServiceRegistration* registration);

  // Initializes all services available for Las Venturas Playground. This cannot be done in the
  // constructor as we can't guarantee a fully initialized Playground instance there.
  void Initialize(Playground* playground);

  // Returns the service identified by |name|. A nullptr will be returned if the service does
  // not exist. The service will be initialized if it's defined, but has not been created yet.
  Service* GetService(const char* name);

 private:
  // Initializes an individual service and registers it in |services_|.
  void InitializeService(const char* name, ServiceRegistration* registration);

  // Contains the services registered for Las Venturas Playground. Registered services will still
  // have to be initialized at this point.
  static std::unordered_map<const char*, ServiceRegistration*> s_registered_services_;

  // Contains the active services for the current Las Venturas Playground instance.
  std::unordered_map<const char*, std::shared_ptr<Service>> services_;

  // Instance of the Playground class which owns this manager. This member will only be set during
  // service initialization, to allow for a service declaring its dependencies.
  Playground* playground_;
};

#endif  // PLAYGROUND_SERVICES_SERVICE_MANAGER_H_
