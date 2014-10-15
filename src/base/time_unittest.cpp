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

#include "base/time_span.h"
#include "gtest/gtest.h"

#include <thread>

TEST(TimeTest, IncreasingTime) {
  Time start = Time::Now();

  // Multiple values of a monotonicly increasing clock must never return the same value, so if the
  // clock backing Time is monotonic, ensure that it is.
  if (Time::IsMonotonic())
    EXPECT_GT(Time::Now(), start);
  
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  Time end = Time::Now();

  EXPECT_GT(end, start);
  EXPECT_GE(end - start, TimeSpan::FromMilliseconds(10));
}

TEST(TimeTest, AdditionAndSubstraction) {
  Time start = Time::Now();
  EXPECT_GT(start + TimeSpan::FromSeconds(10), start);
  EXPECT_GT(start + TimeSpan::FromMicroseconds(1), start);
  EXPECT_LT(start - TimeSpan::FromSeconds(10), start);
  EXPECT_LT(start - TimeSpan::FromMicroseconds(1), start);

  Time base, addition;
  addition += TimeSpan::FromMicroseconds(1);
  EXPECT_GT(addition, base);
  addition -= TimeSpan::FromMicroseconds(1);
  EXPECT_EQ(addition, base);
}

TEST(TimeTest, ComparisonTest) {
  Time t1, t2;
  t1 += TimeSpan::FromSeconds(10);
  t2 += TimeSpan::FromSeconds(20);

  EXPECT_EQ(t2, t2);
  EXPECT_NE(t2, t1);
  EXPECT_LT(t1, t2);
  EXPECT_LE(t1, t2);
  EXPECT_LE(t1, t1);
  EXPECT_GT(t2, t1);
  EXPECT_GE(t2, t2);
}
