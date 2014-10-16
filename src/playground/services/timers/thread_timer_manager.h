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

#ifndef PLAYGROUND_SERVICES_TIMERS_THREAD_TIMER_MANAGER_H_
#define PLAYGROUND_SERVICES_TIMERS_THREAD_TIMER_MANAGER_H_

#include <queue>

class Timer;

// Each thread in Las Venturas Playground has its own timer manager, and it is the responsibility of
// the thread's owner (either the Playground instance for the server, or a MessageLoop for any other
// thread) to make sure timers get invoked.
class ThreadTimerManager {
 public:
  // Returns the ThreadTimerManager instance for the current thread.
  static ThreadTimerManager* InstanceForThread();

  // Shuts down this thread timer manager. All pending timers will be invalidated and removed.
  void Shutdown();

  // Registers |timer| as a new timer with the manager, causing it to be invoked in due course.
  void RegisterTimer(Timer* timer);

  // Removes |timer| from the list of timers maintained by this manager. It will no longer be
  // functional until it re-registers itself.
  void RemoveTimer(Timer* timer);

  // Processes all timers currently in the queue for this thread.
  void ProcessTimers();

 private:
  ThreadTimerManager();

  // Merges the timers stored in |new_timers_| in to the |active_timers_| queue. We need to
  // maintain two separate queues because invocating a timer could immediately queue another
  // timer, which means we could end up in a (near-)infinite loop when processing them.
  void MergeTimerQueues();

  // Makes sure that timers in the active timer queue are sorted based on their intended
  // execution time. Timers which have to fire soonest must come first in the queue.
  struct TimerInvocationTimeComperator {
    bool operator()(const Timer* left, const Timer* right);
  };

  typedef std::priority_queue<Timer*, std::vector<Timer*>, TimerInvocationTimeComperator> ActiveTimerQueue;
  ActiveTimerQueue active_timers_;

  std::queue<Timer*> new_timers_;
};

#endif  // PLAYGROUND_SERVICES_TIMERS_THREAD_TIMER_MANAGER_H_
