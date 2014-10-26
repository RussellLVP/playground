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

#include "playground/communication/message_builder.h"

#include <iomanip>
#include <locale>

namespace {

// Force using a comma as a thousand separator regardless of the locale.
class thousand_separator_numpunct : public std::numpunct<char> {
 protected:
  virtual char do_thousands_sep() const override {
    return ',';
  }
  virtual std::string do_grouping() const override {
    return "\3";
  }
};

}  // namespace

MessageBuilder::MessageBuilder() {}

MessageBuilder::MessageBuilder(Color color)
    : color_(color), current_color_(color) {}

MessageBuilder::MessageBuilder(const std::string& message) {
  stream_ << message;
}

MessageBuilder::MessageBuilder(const std::string& message, Color color)
    : color_(color), current_color_(color) {
  stream_ << message;
}

MessageBuilder& MessageBuilder::Append(const std::string& value) {
  return Append(value, color_);
}

MessageBuilder& MessageBuilder::Append(const std::string& value, Color color) {
  if (current_color_ != color)
    SetColor(color);

  stream_ << value;
  return *this;
}

MessageBuilder& MessageBuilder::Append(double value) {
  return Append(value, 3, color_);
}

MessageBuilder& MessageBuilder::Append(double value, int decimals) {
  return Append(value, decimals, color_);
}

MessageBuilder& MessageBuilder::Append(double value, Color color) {
  return Append(value, 3, color);
}

MessageBuilder& MessageBuilder::Append(double value, int decimals, Color color) {
  if (current_color_ != color)
    SetColor(color);

  stream_ << std::setprecision(decimals) << value;
  return *this;
}

MessageBuilder& MessageBuilder::AppendMoney(int money) {
  return AppendMoney(money, color_);
}

MessageBuilder& MessageBuilder::AppendMoney(int money, Color color) {
  if (current_color_ != color)
    SetColor(color);

  std::locale locale(std::locale(), new thousand_separator_numpunct());

  std::stringstream stream;
  stream.imbue(locale);
  stream << "$";
  stream << std::fixed << money;

  stream_ << stream.str();
  return *this;
}

std::string MessageBuilder::ToString() const {
  return stream_.str();
}

void MessageBuilder::SetColor(Color color) {
  stream_ << "{";
  stream_ << std::hex << std::setfill('0')
          << std::setw(2) << static_cast<int>(color.R)
          << std::setw(2) << static_cast<int>(color.G)
          << std::setw(2) << static_cast<int>(color.B);

  stream_ << "}";

  current_color_ = color;
}
