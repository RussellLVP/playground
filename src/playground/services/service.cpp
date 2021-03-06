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

#include "playground/services/service.h"

#include "base/logging.h"
#include "playground/playground.h"

Service::Service(Playground* playground)
    : playground_(playground) {
  DCHECK(playground);
}

JsonObject Service::configuration() const {
  return playground_->configuration().GetObject("services").GetObject(service_name());
}

ChatManager& Service::chat_manager() const {
  return playground_->chat_manager();
}

PlayerManager& Service::player_manager() const {
  return playground_->player_manager();
}
