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

#ifndef BASE_TIME_H_
#define BASE_TIME_H_

#include <chrono>

#include "base/time_span.h"

// The Time class represents a particular point in time. New representations can be created by using
// mathematical operators and TimeSpan instances. Time objects should only be stack-allocated.
class Time {
 public:
  // Returns a Time instance representing the current moment in time.
  static Time Now();

  // Returns whether times contained by the Time class are monotonic.
  static bool IsMonotonic();

  // Initializes an empty Time object, not pointing to any particular point in time.
  Time() : time_() {}

  // Allow substracting two Time objects, resulting in a TimeSpan value.
  TimeSpan operator-(const Time& other) const;

  // Allow creating new time objects or mutating this one by adding or substracting durations.
  Time operator+(const TimeSpan& duration) const;
  Time& operator+=(const TimeSpan& duration);
  Time operator-(const TimeSpan& duration) const;
  Time& operator-=(const TimeSpan& duration);

  // Allow comparisons between different TimeSpan values to take place.
  bool operator==(const Time& other) const { return time_ == other.time_; }
  bool operator!=(const Time& other) const { return time_ != other.time_; }
  bool operator>(const Time& other) const { return time_ > other.time_; }
  bool operator>=(const Time& other) const { return time_ >= other.time_; }
  bool operator<(const Time& other) const { return time_ < other.time_; }
  bool operator<=(const Time& other) const { return time_ <= other.time_; }

 private:
  // The clock which should back the Time implementation.
  typedef std::chrono::high_resolution_clock clock;

  Time(clock::time_point time) : time_(time) {}

  clock::time_point time_;
};

#endif  // BASE_TIME_H_
