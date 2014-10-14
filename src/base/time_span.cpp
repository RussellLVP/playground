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

#include "base/time_span.h"

#include <stdio.h>

namespace {
const unsigned int kHoursToMicroseconds = 60 * 60 * 1000 * 1000;
const unsigned int kMinutesToMicroseconds = 60 * 1000 * 1000;
const unsigned int kSecondsToMicroseconds = 1000 * 1000;
const unsigned int kMillisecondsToMicroseconds = 1000;
}

// static
TimeSpan TimeSpan::FromHours(uint64_t hours) {
  return TimeSpan(hours * kHoursToMicroseconds);
}

// static
TimeSpan TimeSpan::FromMinutes(uint64_t minutes) {
  return TimeSpan(minutes * kMinutesToMicroseconds);
}

// static
TimeSpan TimeSpan::FromSeconds(uint64_t seconds) {
  return TimeSpan(seconds * kSecondsToMicroseconds);
}

// static
TimeSpan TimeSpan::FromMilliseconds(uint64_t milliseconds) {
  return TimeSpan(milliseconds * kMillisecondsToMicroseconds);
}

// static
TimeSpan TimeSpan::FromMicroseconds(uint64_t microseconds) {
  return TimeSpan(microseconds);
}

uint64_t TimeSpan::InHours() const {
  return static_cast<uint64_t>(duration_ / kHoursToMicroseconds);
}

uint64_t TimeSpan::InMinutes() const {
  return static_cast<uint64_t>(duration_ / kMinutesToMicroseconds);
}

uint64_t TimeSpan::InSeconds() const {
  return static_cast<uint64_t>(duration_ / kSecondsToMicroseconds);
}

uint64_t TimeSpan::InMilliseconds() const {
  return static_cast<uint64_t>(duration_ / kMillisecondsToMicroseconds);
}

uint64_t TimeSpan::InMicroseconds() const {
  return duration_;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& other) {
  duration_ += other.duration_;
  return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& other) {
  if (other.duration_ > duration_)
    duration_ = 0;  // don't underflow.
  else
    duration_ -= other.duration_;

  return *this;
}

TimeSpan& TimeSpan::operator/=(uint64_t denominator) {
  duration_ /= denominator;
  return *this;
}

TimeSpan& TimeSpan::operator*=(uint64_t factor) {
  duration_ *= factor;
  return *this;
}
