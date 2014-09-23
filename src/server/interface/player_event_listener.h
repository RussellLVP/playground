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

#ifndef SERVER_INTERFACE_PLAYER_EVENT_LISTENER_H_
#define SERVER_INTERFACE_PLAYER_EVENT_LISTENER_H_

// The player event listener defines the events which will be triggered for players connecting to
// the server. This is done at a higher level than the SA-MP event handling, in that we pass in the
// Player objects and C++ types rather than the Pawn runtime information.
class PlayerEventListener {
 public:
  virtual ~PlayerEventListener() {}

  virtual void OnPlayerConnect() = 0;
};

#endif  // SERVER_INTERFACE_PLAYER_EVENT_LISTENER_H_
