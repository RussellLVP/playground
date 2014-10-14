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

#include "gtest/gtest.h"

TEST(TimeSpanTest, UnitConversions) {
  uint64_t hour_value = 24;
  TimeSpan hours = TimeSpan::FromHours(hour_value);
  EXPECT_EQ(hour_value, hours.InHours());  // 24
  EXPECT_EQ(hour_value * 60, hours.InMinutes());  // 1440
  EXPECT_EQ(hour_value * 60 * 60, hours.InSeconds());  // 86400
  EXPECT_EQ(hour_value * 60 * 60 * 1000, hours.InMilliseconds());  // 86400000
  EXPECT_EQ(hour_value * 60 * 60 * 1000 * 1000, hours.InMicroseconds());  // 86400000000

  uint64_t minute_value = 300;
  TimeSpan minutes = TimeSpan::FromMinutes(minute_value);
  EXPECT_EQ(minute_value / 60, minutes.InHours());  // 5
  EXPECT_EQ(minute_value, minutes.InMinutes());  // 300
  EXPECT_EQ(minute_value * 60, minutes.InSeconds());  // 18000
  EXPECT_EQ(minute_value * 60 * 1000, minutes.InMilliseconds());  // 18000000
  EXPECT_EQ(minute_value * 60 * 1000 * 1000, minutes.InMicroseconds());  // 18000000000

  uint64_t second_value = 3600;
  TimeSpan seconds = TimeSpan::FromSeconds(second_value);
  EXPECT_EQ(second_value / 60 / 60, seconds.InHours());  // 1
  EXPECT_EQ(second_value / 60, seconds.InMinutes());  // 60
  EXPECT_EQ(second_value, seconds.InSeconds());  // 3600
  EXPECT_EQ(second_value * 1000, seconds.InMilliseconds());  // 3600000
  EXPECT_EQ(second_value * 1000 * 1000, seconds.InMicroseconds());  // 3600000000

  uint64_t millisecond_value = 10800000;
  TimeSpan milliseconds = TimeSpan::FromMilliseconds(millisecond_value);
  EXPECT_EQ(millisecond_value / 1000 / 60 / 60, milliseconds.InHours());  // 3
  EXPECT_EQ(millisecond_value / 1000 / 60, milliseconds.InMinutes());  // 180
  EXPECT_EQ(millisecond_value / 1000, milliseconds.InSeconds());  // 10800
  EXPECT_EQ(millisecond_value, milliseconds.InMilliseconds());  // 10800000
  EXPECT_EQ(millisecond_value * 1000, milliseconds.InMicroseconds());  // 10800000000

  uint64_t microsecond_value = 7200000000;
  TimeSpan microseconds = TimeSpan::FromMicroseconds(microsecond_value);
  EXPECT_EQ(microsecond_value / 1000 / 1000 / 60 / 60, microseconds.InHours());  // 2
  EXPECT_EQ(microsecond_value / 1000 / 1000 / 60, microseconds.InMinutes());  // 120
  EXPECT_EQ(microsecond_value / 1000 / 1000, microseconds.InSeconds());  // 7200
  EXPECT_EQ(microsecond_value / 1000, microseconds.InMilliseconds());  // 7200000
  EXPECT_EQ(microsecond_value, microseconds.InMicroseconds());  // 7200000000
}

TEST(TimeSpanTest, AdditionAndSubstraction) {
  EXPECT_EQ(23, (TimeSpan::FromHours(24) - TimeSpan::FromMinutes(60)).InHours());
  EXPECT_EQ(23, (TimeSpan::FromMinutes(24) - TimeSpan::FromSeconds(60)).InMinutes());
  EXPECT_EQ(25, (TimeSpan::FromHours(24) + TimeSpan::FromMinutes(60)).InHours());
  EXPECT_EQ(25, (TimeSpan::FromMinutes(24) + TimeSpan::FromSeconds(60)).InMinutes());

  TimeSpan hours = TimeSpan::FromHours(48);
  hours -= TimeSpan::FromMinutes(120);
  EXPECT_EQ(46, hours.InHours());

  TimeSpan minutes = TimeSpan::FromMinutes(300);
  minutes += TimeSpan::FromHours(2);
  EXPECT_EQ(7, minutes.InHours());

  TimeSpan seconds = TimeSpan::FromSeconds(60);
  seconds -= TimeSpan::FromHours(100);
  EXPECT_EQ(0, seconds.InMicroseconds());
}

TEST(TimeSpanTest, DivisionAndMultiplication) {
  EXPECT_EQ(60, (TimeSpan::FromHours(30) * 2).InHours());
  EXPECT_EQ( 3, (TimeSpan::FromHours(30) / 10).InHours());

  TimeSpan hours = TimeSpan::FromHours(48);
  hours *= 2;
  EXPECT_EQ(96, hours.InHours());

  TimeSpan minutes = TimeSpan::FromMinutes(120);
  minutes /= 60;
  EXPECT_EQ(2, minutes.InMinutes());
}

TEST(TimeSpanTest, Comparisons) {
  EXPECT_TRUE(TimeSpan::FromHours(24) > TimeSpan::FromHours(23));
  EXPECT_TRUE(TimeSpan::FromHours(24) >= TimeSpan::FromHours(23));
  EXPECT_TRUE(TimeSpan::FromHours(24) >= TimeSpan::FromHours(24));
  EXPECT_TRUE(TimeSpan::FromHours(24) == TimeSpan::FromMinutes(24 * 60));
  EXPECT_TRUE(TimeSpan::FromHours(10) != TimeSpan::FromHours(20));
  EXPECT_TRUE(TimeSpan::FromHours(10) < TimeSpan::FromMinutes(11 * 60));
  EXPECT_TRUE(TimeSpan::FromHours(10) <= TimeSpan::FromMinutes(11 * 60));
  EXPECT_TRUE(TimeSpan::FromHours(10) <= TimeSpan::FromMinutes(10 * 60));
}
