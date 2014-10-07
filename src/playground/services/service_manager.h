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
  // Registers a service called |name| provided by |registration|.
  static void RegisterService(const char* name, ServiceRegistration* registration);

  // Initializes all services available for Las Venturas Playground. This cannot be done in the
  // constructor as we can't guarantee a fully initialized Playground instance there.
  void Initialize(Playground* playground);

 private:
  // Contains the services registered for Las Venturas Playground.
  static std::unordered_map<const char*, ServiceRegistration*> s_registered_services_;

  // Contains the active services for the current Las Venturas Playground instance.
  std::unordered_map<const char*, std::unique_ptr<ServiceBase>> services_;
};

// Helper structure which can be used as a static initializer to register a service with the service
// manager, ensuring that it can be initialized by the service manager when required.
struct ServiceRegistration {
  virtual ServiceBase* Create(Playground* playground) = 0;
};

template <class ServiceImpl>
struct ServiceRegistrationImpl : public ServiceRegistration {
  explicit ServiceRegistrationImpl(const char* name) {
    ServiceManager::RegisterService(name, this);
  }

  virtual ServiceBase* Create(Playground* playground) override {
    return ServiceImpl::Create(playground);
  }
};

#endif  // PLAYGROUND_SERVICES_SERVICE_MANAGER_H_
