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

#ifndef SERVER_LISTENERS_CHAT_EVENT_LISTENER_H_
#define SERVER_LISTENERS_CHAT_EVENT_LISTENER_H_

#include <string>

namespace samp {

// The chat event listener allows features to listen in to incoming messages in the SA-MP chatbox,
// as sent by other players. These events are cancellable.
class ChatEventListener {
 public:
  virtual ~ChatEventListener() {}

  virtual bool OnPlayerText(int player_id, const std::string& message) = 0;
};

}  // namespace samp

#endif  // SERVER_LISTENERS_CHAT_EVENT_LISTENER_H_
