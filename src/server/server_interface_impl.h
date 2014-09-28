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

#ifndef SERVER_SERVER_INTERFACE_IMPL_H_
#define SERVER_SERVER_INTERFACE_IMPL_H_

#include <list>

#include "server/interface/samp/event_listener.h"
#include "server/native_function_manager.h"
#include "server/server_interface.h"
#include "server/server_log_delegate.h"

class ServerInterfaceImpl : public ServerInterface,
                            public samp::EventListener {
 public:
  explicit ServerInterfaceImpl(void** data);
  virtual ~ServerInterfaceImpl();

  // ServerInterface implementation.
  virtual void ProvideNativeFunction(const std::string& name, const NativeFunction& implementation) override;
  virtual void AttachEventListener(PlayerEventListener* player_event_listener) override;
  virtual void RemoveEventListener(PlayerEventListener* player_event_listener) override;
  virtual void DidLoadScript(AMX* amx) override;
  virtual void DidUnloadScript(AMX* amx) override;

  // samp::EventListener implementation.
  virtual void OnPlayerConnect(int player_id) override;

 private:
  NativeFunctionManager native_function_manager_;
  ServerLogDelegate log_delegate_;

  std::list<PlayerEventListener*> player_event_listeners_;
};

#endif  // SERVER_SERVER_INTERFACE_IMPL_H_
