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

#ifndef PLAYGROUND_SERVICES_SERVICE_CONFIGURATION_H_
#define PLAYGROUND_SERVICES_SERVICE_CONFIGURATION_H_

class Playground;

// Provides read-only access to the configuration belonging to this specific service. It's fed by
// the Configuration class owned by Playground.
class ServiceConfiguration {
 public:
  ServiceConfiguration(Playground* playground, const char* service_name);

 private:
  Playground* playground_;
  const char* service_name_;
};

#endif  // PLAYGROUND_SERVICES_SERVICE_CONFIGURATION_H_
