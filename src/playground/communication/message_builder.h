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

#ifndef PLAYGROUND_COMMUNICATION_MESSAGE_BUILDER_H_
#define PLAYGROUND_COMMUNICATION_MESSAGE_BUILDER_H_

#include <sstream>
#include <string>

#include "base/color.h"

// Allows for convenient building of messages which are to be distributed to players. The builder
// provides for efficient appending of parts, as well as formatting and custom colors.
class MessageBuilder {
 public:
  MessageBuilder();
  explicit MessageBuilder(Color color);
  explicit MessageBuilder(const std::string& message);
  MessageBuilder(const std::string& message, Color color);

  // Appends |value| to the message, optionally specifying the color it should be written in.
  MessageBuilder& Append(const std::string& value);
  MessageBuilder& Append(const std::string& value, Color color);

  // Append monetary values to the message. The number will automatically be formatted.
  MessageBuilder& AppendMoney(int money);
  MessageBuilder& AppendMoney(int money, Color color);

  // Returns the contents of this message builder as a string.
  std::string ToString() const;

  // Returns the base color of this message.
  const Color& color() const { return color_; }

 private:
  // Sets the color in the stream to match |color|.
  void SetColor(Color color);

  Color color_;
  Color current_color_;

  std::stringstream stream_;
};

#endif  // PLAYGROUND_COMMUNICATION_MESSAGE_BUILDER_H_
