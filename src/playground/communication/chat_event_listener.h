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

#ifndef PLAYGROUND_COMMUNICATION_CHAT_EVENT_LISTENER_H_
#define PLAYGROUND_COMMUNICATION_CHAT_EVENT_LISTENER_H_

#include <string>

class Player;

// Defines the higher level chat events which features can tie in to to receive chat messages send
// by players. For cancellable events, all event listeners will be invoked.
class ChatEventListener {
 public:
  virtual ~ChatEventListener() {}
  
  // Triggered when |player| sends |message| to the chatbox. |cancelled| indicates whether a previous
  // listener cancelled distribution of the message to other players.
  virtual bool OnPlayerText(Player* player, const std::string& message, bool cancelled) = 0;

};

#endif  // PLAYGROUND_COMMUNICATION_CHAT_EVENT_LISTENER_H_
