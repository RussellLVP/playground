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

#ifndef PLAYGROUND_ENTITIES_PLAYER_EVENT_LISTENER_H_
#define PLAYGROUND_ENTITIES_PLAYER_EVENT_LISTENER_H_

class Player;

// Contains empty implementations of the events available for players. Classes which register
// themselves as player event listeners will be able to override any they need.
class PlayerEventListener {
 public:
  virtual ~PlayerEventListener() {}

  virtual void OnPlayerConnect(Player* player) {}
  virtual void OnPlayerDisconnect(Player* player) {}
};

#endif  // PLAYGROUND_ENTITIES_PLAYER_EVENT_LISTENER_H_
