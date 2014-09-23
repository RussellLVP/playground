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

#include "server/server_interface_impl.h"

#include "server/sdk/plugincommon.h"

// -------------------------------------------------------------------------------------------------

// Static. Declared in /server/server_interface.h.
ServerInterface* ServerInterface::Create(void** data) {
  return new ServerInterfaceImpl(data);
}

// -------------------------------------------------------------------------------------------------

ServerInterfaceImpl::ServerInterfaceImpl(void** data) {}

ServerInterfaceImpl::~ServerInterfaceImpl() {}

void ServerInterfaceImpl::DidLoadScript(AMX* amx) {}

void ServerInterfaceImpl::DidUnloadScript(AMX* amx) {}

void ServerInterfaceImpl::OnPlayerConnect(int player_id) {}
