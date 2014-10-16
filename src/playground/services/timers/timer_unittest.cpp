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

#include "playground/services/timers/timer.h"

#include <thread>

#include "gtest/gtest.h"
#include "playground/services/timers/thread_timer_manager.h"

// Timers require a clean run-time of the server environment, so before each test we clear out the
// timer manager for the thread these tests are being ran on.
class TimerTest : public testing::Test {
 public:
  virtual void SetUp() override {
    primary_invocation_count_ = 0;
    secondary_invocation_count_ = 0;

    // This completely clears out the state of the thread timer manager.
    ThreadTimerManager::InstanceForThread()->Shutdown();
  }

  void PrimaryCounter() { ++primary_invocation_count_; }
  void SecondaryCounter() { ++secondary_invocation_count_; }

  unsigned int primary_invocation_count() const { return primary_invocation_count_; }
  unsigned int secondary_invocation_count() const { return secondary_invocation_count_; }

 private:
  unsigned int primary_invocation_count_;
  unsigned int secondary_invocation_count_;
};

// -------------------------------------------------------------------------------------------------

static void SecondThreadTimerTest(TimerTest* instance) {
  Timer timer(std::bind(&TimerTest::SecondaryCounter, instance));
  timer.Start(TimeSpan::FromMicroseconds(0), false);

  EXPECT_EQ(0, instance->secondary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, instance->secondary_invocation_count());

  ThreadTimerManager::InstanceForThread()->Shutdown();
}

// -------------------------------------------------------------------------------------------------


TEST_F(TimerTest, ImmediateOneShotTimer) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  EXPECT_FALSE(timer.is_active());
  timer.Start(TimeSpan::FromMicroseconds(0), false);
  EXPECT_FALSE(timer.is_repeating());
  EXPECT_TRUE(timer.is_active());

  EXPECT_EQ(0, primary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, primary_invocation_count());
}

TEST_F(TimerTest, ImmediateRepeatedTimer) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  timer.Start(TimeSpan::FromMicroseconds(0), true);
  EXPECT_TRUE(timer.is_repeating());

  EXPECT_EQ(0, primary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, primary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(2, primary_invocation_count());
}

TEST_F(TimerTest, DelayedOneShotTimer) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  timer.Start(TimeSpan::FromMilliseconds(4), false);

  EXPECT_EQ(0, primary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(0, primary_invocation_count());

  std::this_thread::sleep_for(std::chrono::milliseconds(5));

  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, primary_invocation_count());
}

TEST_F(TimerTest, DelayedRepeatedTimer) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  timer.Start(TimeSpan::FromMilliseconds(2), true);

  EXPECT_EQ(0, primary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(0, primary_invocation_count());

  std::this_thread::sleep_for(std::chrono::milliseconds(3));

  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, primary_invocation_count());
  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, primary_invocation_count());

  std::this_thread::sleep_for(std::chrono::milliseconds(3));

  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(2, primary_invocation_count());
}

TEST_F(TimerTest, MultipleTimers) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  timer.Start(TimeSpan::FromMicroseconds(0), true);

  Timer delayed_timer(std::bind(&TimerTest::SecondaryCounter, this));
  delayed_timer.Start(TimeSpan::FromMilliseconds(2), true);

  EXPECT_EQ(0, primary_invocation_count());
  EXPECT_EQ(0, secondary_invocation_count());

  ThreadTimerManager::InstanceForThread()->ProcessTimers();

  EXPECT_EQ(1, primary_invocation_count());
  EXPECT_EQ(0, secondary_invocation_count());

  std::this_thread::sleep_for(std::chrono::milliseconds(3));
  ThreadTimerManager::InstanceForThread()->ProcessTimers();

  EXPECT_EQ(2, primary_invocation_count());
  EXPECT_EQ(1, secondary_invocation_count());

  ThreadTimerManager::InstanceForThread()->ProcessTimers();

  EXPECT_EQ(3, primary_invocation_count());
  EXPECT_EQ(1, secondary_invocation_count());
}

TEST_F(TimerTest, MultipleThreads) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  timer.Start(TimeSpan::FromMicroseconds(0), true);

  EXPECT_TRUE(timer.is_active());
  EXPECT_EQ(0, primary_invocation_count());
  
  std::thread thread(SecondThreadTimerTest, this);
  thread.join();

  EXPECT_TRUE(timer.is_active());
  EXPECT_EQ(0, primary_invocation_count());
  EXPECT_EQ(1, secondary_invocation_count());
}

TEST_F(TimerTest, ActiveTimer) {
  Timer timer(std::bind(&TimerTest::PrimaryCounter, this));
  EXPECT_FALSE(timer.is_active());
  timer.Start(TimeSpan::FromMicroseconds(0), true);
  EXPECT_TRUE(timer.is_active());
  ThreadTimerManager::InstanceForThread()->Shutdown();
  EXPECT_FALSE(timer.is_active());

  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(0, primary_invocation_count());

  timer.Start(TimeSpan::FromMicroseconds(0), true);
  EXPECT_TRUE(timer.is_active());

  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_TRUE(timer.is_active());
  EXPECT_EQ(1, primary_invocation_count());

  timer.Stop();
  EXPECT_FALSE(timer.is_active());

  ThreadTimerManager::InstanceForThread()->ProcessTimers();
  EXPECT_EQ(1, primary_invocation_count());
}
