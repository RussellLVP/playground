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

#include "playground/communication/chat_manager.h"

#include "base/logging.h"
#include "playground/communication/chat_event_listener.h"
#include "playground/entities/player_manager.h"
#include "playground/playground.h"

ChatManager::ChatManager(Playground* playground)
    : playground_(playground) {}

ChatManager::~ChatManager() {}

void ChatManager::AttachEventListener(::ChatEventListener* listener) {
  event_listeners_.push_back(listener);
}

bool ChatManager::OnPlayerText(int player_id, const std::string& message) {
  Player* player = playground_->player_manager().Get(player_id);
  if (!player) {
    LOG(WARNING) << "Chat message received from invalid player " << player_id << ": " << message;
    return false;
  }

  if (!message.length()) {
    LOG(WARNING) << "Empty chat message received from player " << player_id << ".";
    return false;
  }

  bool cancelled = false;
  for (auto* listener : event_listeners_)
    cancelled = !listener->OnPlayerText(player, message, cancelled);

  return cancelled;
}
