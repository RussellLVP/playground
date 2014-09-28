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

#ifndef SERVER_SERVER_LOG_DELEGATE_H_
#define SERVER_SERVER_LOG_DELEGATE_H_

#include "base/logging.h"

typedef void (*logprintf_t)(char *format, ...);

// Delegate which we use to route logging output created by the plugin to the SA-MP server console,
// also ensuring that the messages end up in log files.
class ServerLogDelegate : public logging::LogMessage::Delegate {
 public:
  explicit ServerLogDelegate(logprintf_t logprintf);
  ~ServerLogDelegate();

  // LogMessage::Delegate implementation.
  virtual bool WriteMessage(const std::string& message) override;

 private:
  logprintf_t logprintf_;
};

#endif  // SERVER_SERVER_LOG_DELEGATE_H_
