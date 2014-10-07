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

#ifndef PLAYGROUND_SERVICES_SERVICE_MACROS_H_
#define PLAYGROUND_SERVICES_SERVICE_MACROS_H_

// Defines the required machinery in the service's header file required for it to work well. Right
// now we define a the base class as a friend, allowing the constructor to be non-public, and a
// static which enables getting the name of the service.
#define DECLARE_SERVICE(Implementation) \
 public: \
  static const char* GetName() { return #Implementation; } \
 private: \
  friend class Service<Implementation>;

// Defines the service which is implemented in the |Implementation| class. This will create a static
// initializer that will register the service with the service manager.
#define DEFINE_SERVICE(Implementation) \
  ServiceRegistrationImpl<Implementation> registration(Implementation::GetName());

#endif  // PLAYGROUND_SERVICES_SERVICE_MACROS_H_
