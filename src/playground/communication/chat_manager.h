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

#ifndef PLAYGROUND_COMMUNICATION_CHAT_MANAGER_H_
#define PLAYGROUND_COMMUNICATION_CHAT_MANAGER_H_

#include <list>
#include <string>

#include "server/listeners/chat_event_listener.h"

class ChatEventListener;
class Playground;

// The chat manager is responsible for curating the messages which players send to the chatbox on
// Las Venturas Playground. It also powers the //playground-level event listener.
class ChatManager : public samp::ChatEventListener {
 public:
  explicit ChatManager(Playground* playground);
  virtual ~ChatManager();

  // Sends |message| to all players on Las Venturas Playground.
  void DistributeMessage(const std::string& message);

  // Registers |listener| as an event listener for any event related to the chat manager.
  // TODO(Russell): Event unregistration should be automatic; make |listener| weak.
  void AttachEventListener(::ChatEventListener* listener);

  // samp::ChatEventListener implementation.
  virtual bool OnPlayerText(int player_id, const std::string& message) override;

 private:
  // Weak reference to the Playground instance which owns this chat manager.
  Playground* playground_;

  std::list<::ChatEventListener*> event_listeners_;
};

#endif  // PLAYGROUND_COMMUNICATION_CHAT_MANAGER_H_
