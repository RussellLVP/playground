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

#include "playground/playground.h"

#include "base/logging.h"
#include "playground/communication/chat_manager.h"
#include "playground/configuration.h"
#include "playground/entities/player_manager.h"
#include "playground/services/service_manager.h"
#include "playground/services/timers/thread_timer_manager.h"
#include "server/server_interface.h"

namespace {

// File the configuration for Las Venturas Playground resides in.
const char kConfigurationFile[] = "playground.json";

}  // namespace

Playground::Playground(ServerInterface* server_interface)
    : server_interface_(server_interface),
      service_manager_(new ServiceManager()) {
  configuration_ = Configuration::FromFile(kConfigurationFile);
  if (!configuration_) {
    if (!server_interface->IsRunningTest())
      LOG(ERROR) << "Unable to load the configuration file (" << kConfigurationFile << ").";

    configuration_ = Configuration::FromDefaults();
    CHECK(configuration_);
  }

  chat_manager_.reset(new ChatManager(this));
  server_interface_->AttachEventListener(chat_manager_.get());

  player_manager_.reset(new PlayerManager());
  server_interface_->AttachEventListener(player_manager_.get());

  service_manager_->Initialize(this);
}

Playground::~Playground() {
  ThreadTimerManager::InstanceForThread()->Shutdown();
}

void Playground::ProcessTick() {
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
}

JsonObject Playground::configuration() const {
  return configuration_->object();
}
