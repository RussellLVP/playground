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

#ifndef BASE_TIME_SPAN_H_
#define BASE_TIME_SPAN_H_

#include <stdint.h>

// The TimeSpan structure represents a certain duration of time. It can be initialized either based
// on another TimeSpan instance, empty or based on a duration in a specific unit of time. TimeSpan
// structures should only be stack allocated.
class TimeSpan {
 public:
  // Initializes a new TimeSpan covering the indicated unit.
  static TimeSpan FromHours(uint64_t hours);
  static TimeSpan FromMinutes(uint64_t value);
  static TimeSpan FromSeconds(uint64_t seconds);
  static TimeSpan FromMilliseconds(uint64_t milliseconds);
  static TimeSpan FromMicroseconds(uint64_t microseconds);

  // Returns the value contained by this TimeSpan in the indicated unit.
  uint64_t InHours() const;
  uint64_t InMinutes() const;
  uint64_t InSeconds() const;
  uint64_t InMilliseconds() const;
  uint64_t InMicroseconds() const;

  // Initializes a new TimeSpan based on another TimeSpan.
  TimeSpan(const TimeSpan& other) : duration_(other.duration_) {}
  TimeSpan() : duration_(0) {}

  // Allow additions and substractions between different TimeSpans.
  TimeSpan& operator+=(const TimeSpan& other);
  TimeSpan operator+(const TimeSpan& other) const {
    return TimeSpan(duration_ + other.duration_);
  }

  TimeSpan& operator-=(const TimeSpan& other);
  TimeSpan operator-(const TimeSpan& other) const {
    return TimeSpan(duration_ - other.duration_);
  }

  // Allow divisions and multiplications based on another integer value.
  TimeSpan& operator/=(uint64_t denominator);
  TimeSpan operator/(uint64_t denominator) const {
    return TimeSpan(static_cast<uint64_t>(duration_ / denominator));
  }

  TimeSpan& operator*=(uint64_t factor);
  TimeSpan operator*(uint64_t factor) const {
    return TimeSpan(duration_ * factor);
  }

  // Allow comparisons between different TimeSpan values to take place.
  bool operator==(const TimeSpan& other) const { return duration_ == other.duration_; }
  bool operator!=(const TimeSpan& other) const { return duration_ != other.duration_; }
  bool operator>(const TimeSpan& other) const { return duration_ > other.duration_; }
  bool operator>=(const TimeSpan& other) const { return duration_ >= other.duration_; }
  bool operator<(const TimeSpan& other) const { return duration_ < other.duration_; }
  bool operator<=(const TimeSpan& other) const { return duration_ <= other.duration_; }

 private:
  explicit TimeSpan(uint64_t duration) : duration_(duration) {}

  uint64_t duration_;
};

#endif  // BASE_TIME_SPAN_H_
