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

#ifndef PLAYGROUND_SERVICES_TIMERS_TIMER_H_
#define PLAYGROUND_SERVICES_TIMERS_TIMER_H_

#include <functional>

#include "base/macros.h"
#include "base/time.h"
#include "base/time_span.h"

// A timer allows for once or repeated invocation of a function after a given delay.
//
// Any service is able to register a timer which will be invoked after the given TimeSpan has
// expired. When it's a repeated timer, the timer will be queued again automatically immediately
// after invocation. Timers will always be invoked on the thread they were created on.
class Timer {
  typedef std::function<void()> CallbackType;

 public:
  Timer(const CallbackType& callback);
  ~Timer();

  // Starts a timer which should fire after |interval|, repetitive if |repeating| is true.
  void Start(TimeSpan interval, bool repeating);

  // Stops the timer if a next invocation is still active.
  void Stop();

  // Returns whether the timer is currently waiting for a next invocation.
  bool is_active() const { return is_active_; }

  // Returns the time at which the fire should next be invoked.
  const Time& next_invocation_time() const { return next_invocation_time_; }

  // Returns whether this timer is a repeating timer or a one-shot.
  bool is_repeating() const { return is_repeating_; }

 private:
  CallbackType callback_;

  Time next_invocation_time_;
  TimeSpan invocation_interval_;
  bool is_repeating_;
  bool is_active_;

  DISALLOW_COPY_AND_ASSIGN(Timer);
};

#endif  // PLAYGROUND_SERVICES_TIMERS_TIMER_H_
