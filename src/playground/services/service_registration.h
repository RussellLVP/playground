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

#ifndef PLAYGROUND_SERVICES_SERVICE_REGISTRATION_H_
#define PLAYGROUND_SERVICES_SERVICE_REGISTRATION_H_

#include <memory>

class Playground;
class Service;

// Helper structure which can be used as a static initializer to register a service with the service
// manager, ensuring that it can be initialized by the service manager when required.
struct ServiceRegistration {
  virtual std::unique_ptr<Service> Create(Playground* playground) = 0;
};

template <class ServiceImpl>
struct ServiceRegistrationImpl : public ServiceRegistration {
  ServiceRegistrationImpl() {
    ServiceManager::RegisterService(ServiceImpl::GetName(), this);
  }

  virtual std::unique_ptr<Service> Create(Playground* playground) override {
    return std::unique_ptr<Service>(new ServiceImpl(playground));
  }
};

#endif  // PLAYGROUND_SERVICES_SERVICE_REGISTRATION_H_
