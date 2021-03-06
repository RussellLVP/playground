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

#include "server/listeners/chat_event_listener.h"
#include "server/listeners/player_event_listener.h"
#include "server/sdk/plugincommon.h"

extern void *pAMXFunctions;

// -------------------------------------------------------------------------------------------------

// Static. Declared in /server/server_interface.h.
ServerInterface* ServerInterface::Create(void** data) {
  return new ServerInterfaceImpl(data);
}

// -------------------------------------------------------------------------------------------------

ServerInterfaceImpl* g_server_interface_impl = nullptr;

ServerInterfaceImpl::ServerInterfaceImpl(void** data)
    : native_callback_interceptor_(data[PLUGIN_DATA_AMX_EXPORTS]),
      log_delegate_(static_cast<logprintf_t>(data[PLUGIN_DATA_LOGPRINTF])),
      is_test_(false) {
  CHECK(!g_server_interface_impl);

  pAMXFunctions = data[PLUGIN_DATA_AMX_EXPORTS];
  if (!pAMXFunctions)
    is_test_ = true;

  native_callback_interceptor_.RegisterNatives(this);
  g_server_interface_impl = this;
}

ServerInterfaceImpl::~ServerInterfaceImpl() {
  g_server_interface_impl = nullptr;
}

// -------------------------------------------------------------------------------------------------

void ServerInterfaceImpl::ProvideNativeFunction(const std::string& name, const NativeFunction& implementation) {
  native_function_manager_.ProvideNativeFunction(name, implementation);
}

// -------------------------------------------------------------------------------------------------

// Because several types of event listeners will be supported, all following exactly the same logic
// for attaching and removing event listeners, we'll avoid manually duplicating a lot of code by
// defining the two methods required for each type as part of a macro.
#define WRITE_EVENT_LISTENER(type, member) \
  void ServerInterfaceImpl::AttachEventListener(samp::type* listener) { \
    member.push_back(listener); \
  } \
  void ServerInterfaceImpl::RemoveEventListener(samp::type* listener) { \
    member.remove(listener); \
  }

WRITE_EVENT_LISTENER(ChatEventListener, chat_event_listeners_);
WRITE_EVENT_LISTENER(PlayerEventListener, player_event_listeners_);

// -------------------------------------------------------------------------------------------------

void ServerInterfaceImpl::DidLoadScript(AMX* amx) {
  native_function_manager_.DidLoadScript(amx);
}

void ServerInterfaceImpl::DidUnloadScript(AMX* amx) {}

// -------------------------------------------------------------------------------------------------

bool ServerInterfaceImpl::IsRunningTest() const {
  return is_test_;
}

// -------------------------------------------------------------------------------------------------

int ServerInterfaceImpl::OnPlayerConnect(int player_id) {
  for (auto& listener : player_event_listeners_)
    listener->OnPlayerConnect(player_id);

  return 1;
}

int ServerInterfaceImpl::OnPlayerDisconnect(int player_id, int reason) {
  for (auto& listener : player_event_listeners_)
    listener->OnPlayerDisconnect(player_id, reason);

  return 1;
}

int ServerInterfaceImpl::OnPlayerText(int player_id, const std::string& message) {
  for (auto& listener : chat_event_listeners_) {
    if (!listener->OnPlayerText(player_id, message))
      return 0;
  }

  return 1;
}
