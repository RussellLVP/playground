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

#include "playground/services/service_manager.h"

#include "base/logging.h"

std::unordered_map<const char*, ServiceRegistration*> ServiceManager::s_registered_services_;

// static
void ServiceManager::RegisterService(const char* name, ServiceRegistration* registration) {
  CHECK(s_registered_services_.find(name) == s_registered_services_.end())
      << "Duplicate service definition found for service " << name << ".";

  s_registered_services_[name] = registration;
}

void ServiceManager::Initialize(Playground* playground) {
  for (auto& service : s_registered_services_) {
    if (services_.find(service.first) != services_.end())
      continue;

    services_[service.first] = std::unique_ptr<ServiceBase>(service.second->Create(playground));
  }
}
