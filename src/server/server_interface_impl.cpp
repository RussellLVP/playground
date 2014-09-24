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

#include "server/interface/player_event_listener.h"

// -------------------------------------------------------------------------------------------------

// Static. Declared in /server/server_interface.h.
ServerInterface* ServerInterface::Create(void** data) {
  return new ServerInterfaceImpl(data);
}

// -------------------------------------------------------------------------------------------------

ServerInterfaceImpl::ServerInterfaceImpl(void** data) {}

ServerInterfaceImpl::~ServerInterfaceImpl() {}

// -------------------------------------------------------------------------------------------------

void ServerInterfaceImpl::ProvideNativeFunction(const std::string& name, const NativeFunction& implementation) {
  native_function_manager_.ProvideNativeFunction(name, implementation);
}

// -------------------------------------------------------------------------------------------------

// Because several types of event listeners will be supported, all following exactly the same logic
// for attaching and removing event listeners, we'll avoid manually duplicating a lot of code by
// defining the two methods required for each type as part of a macro.
#define WRITE_EVENT_LISTENER(type, member) \
  void ServerInterfaceImpl::AttachEventListener(type* listener) { \
    member.push_back(listener); \
  } \
  void ServerInterfaceImpl::RemoveEventListener(type* listener) { \
    member.remove(listener); \
  }

WRITE_EVENT_LISTENER(PlayerEventListener, player_event_listeners_);

// -------------------------------------------------------------------------------------------------

void ServerInterfaceImpl::DidLoadScript(AMX* amx) {
  native_function_manager_.DidLoadScript(amx);
}

void ServerInterfaceImpl::DidUnloadScript(AMX* amx) {}

// -------------------------------------------------------------------------------------------------

void ServerInterfaceImpl::OnPlayerConnect(int player_id) {
  for (PlayerEventListener* listener : player_event_listeners_)
    listener->OnPlayerConnect();
}
