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

#ifndef SERVER_BINDINGS_EVENT_LISTENER_H_
#define SERVER_BINDINGS_EVENT_LISTENER_H_

namespace samp {

// Interface which defines the event listeners that can be provided from a SA-MP environment.
class EventListener {
 public:
  virtual ~EventListener() {}

  virtual int OnPlayerConnect(int player_id) = 0;
  virtual int OnPlayerDisconnect(int player_id, int reason) = 0;
};

}  // namespace samp

#endif  // SERVER_BINDINGS_EVENT_LISTENER_H_
