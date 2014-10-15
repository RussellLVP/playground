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

#include "base/time.h"

// static
Time Time::Now() {
  return Time(clock::now());
}

// static
bool Time::IsMonotonic() {
  return clock::is_steady;
}

TimeSpan Time::operator-(const Time& other) const {
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time_ - other.time_);
  return TimeSpan::FromMicroseconds(duration.count());
}

Time Time::operator+(const TimeSpan& duration) const {
  return Time(time_ + std::chrono::microseconds(duration.InMicroseconds()));
}

Time& Time::operator+=(const TimeSpan& duration) {
  time_ += std::chrono::microseconds(duration.InMicroseconds());
  return *this;
}

Time Time::operator-(const TimeSpan& duration) const {
  return Time(time_ - std::chrono::microseconds(duration.InMicroseconds()));
}

Time& Time::operator-=(const TimeSpan& duration) {
  time_ -= std::chrono::microseconds(duration.InMicroseconds());
  return *this;
}
