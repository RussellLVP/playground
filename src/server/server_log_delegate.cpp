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

#include "server/server_log_delegate.h"

using logging::LogMessage;

ServerLogDelegate::ServerLogDelegate(logprintf_t logprintf)
    : logprintf_(logprintf) {
  if (logprintf_)
    LogMessage::SetDelegate(this);
}

ServerLogDelegate::~ServerLogDelegate() {
  if (logprintf_)
    LogMessage::SetDelegate(nullptr);
}

bool ServerLogDelegate::WriteMessage(const std::string& message) {
  logprintf_("%s", message.c_str());
  return true;
}
