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

#ifndef SERVER_SERVER_INTERFACE_H_
#define SERVER_SERVER_INTERFACE_H_

typedef struct AMX AMX;

// The server interface is the primary layer between the SA-MP server and the Las Venturas
// Playground gamemode logic, neither of which know directly about each other. It also serves as
// the native event delegation class into more specific types.
class ServerInterface {
 public:
  // Creates a new implementation of the ServerInterface class. The |data| argument should be
  // set to whatever the SA-MP server gives us as part of loading the plugin.
  static ServerInterface* Create(void** data);

  // Events which will be triggered by the plugin, and allow the interface to keep track of the
  // available scripts on the server.
  virtual void DidLoadScript(AMX* amx) = 0;
  virtual void DidUnloadScript(AMX* amx) = 0;
};

#endif  // SERVER_SERVER_INTERFACE_H_
