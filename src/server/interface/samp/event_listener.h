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

#ifndef SERVER_INTERFACE_SAMP_EVENT_LISTENER_H_
#define SERVER_INTERFACE_SAMP_EVENT_LISTENER_H_

namespace samp {

// Pure virtual interface defining the available SA-MP events which can be forwarded to the
// implementation. These are direct mappings of the native SA-MP events.
class EventListener {
 public:
  virtual ~EventListener() {}

  virtual void OnPlayerConnect(int player_id) = 0;
};

}  // namespace samp

#endif  // SERVER_INTERFACE_SAMP_EVENT_LISTENER_H_
