// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_LOGGING_H_
#define BASE_LOGGING_H_

#include <sstream>

namespace logging {

class LogMessage {
 public:
  // Logging delegate. May be used to override the destination of messages.
  class Delegate {
   public:
     virtual bool WriteMessage(const std::string& message) = 0;
  };

  // Outputs messages to |delegate| instead of writing to stderr.
  static void SetDelegate(Delegate* delegate);

  // Override the default minimum log severity level to output to STDOUT.
  static void SetMinimumLogSeverity(int level);

  // Get the current minimum log severity level to output to STDOUT.
  static int GetMinimumLogSeverity();

 public:
  LogMessage(const char* file, int line, int severity);
  ~LogMessage();

  // Stream to which additional information can be written.
  std::ostream& stream() { return stream_; }

private:
  static Delegate* delegate_;

  // Initializes the first parts of the message, shared among the constructors.
  void Initialize();

  std::ostringstream stream_;

  int severity_;

  const char* file_;
  const int line_;
};

// Helper class allowing us to disregard logging evaluation.
class LogMessageVoid {
 public:
  LogMessageVoid() { }
  void operator&(std::ostream&) { }
};

// The following severity levels for the LOG() macro are available. A higher level equals a more
// severe message. Fatal messages will abort the program's flow and output a stack trace.
const int LOG_INFO = 0;
const int LOG_WARNING = 1;
const int LOG_ERROR = 2;
const int LOG_FATAL = 3;

}  // namespace logging

// Boolean expression representing whether |severity| should be logged.
#define LOG_IS_ON(severity) \
  ((::logging::LOG_ ## severity) >= ::logging::LogMessage::GetMinimumLogSeverity())

// Creates a new LogMessage instance on the stack for the given |severity| and returns its stream.
#define LOG_STREAM(severity) \
  logging::LogMessage(__FILE__, __LINE__, logging::LOG_ ## severity).stream()

// Macro to help avoid evaluating the arguments to LOG() when the message shouldn't be outputted.
#define LAZY_STREAM(stream, condition) \
  !(condition) ? (void) 0 : ::logging::LogMessageVoid() & (stream)

#ifndef NDEBUG
#define DCHECK_IS_ON 1
#else
#define DCHECK_IS_ON 0
#endif

// LOG(severity) creates a string stream to which output can be written, for a given severity.
#define LOG(severity) \
  LAZY_STREAM(LOG_STREAM(severity), LOG_IS_ON(severity))

#define DLOG(severity) \
  LAZY_STREAM(LOG_STREAM(severity), DCHECK_IS_ON && LOG_IS_ON(severity))

// CHECK(condition) asserts that |condition| evaluates to TRUE, or aborts the program otherwise.
#define CHECK(condition)                       \
  LAZY_STREAM(LOG_STREAM(FATAL), !(condition)) \
  << "Check failed: " #condition ". "

#define DCHECK(condition)                       \
  LAZY_STREAM(LOG_STREAM(FATAL), DCHECK_IS_ON && !(condition)) \
  << "Check failed: " #condition ". "

#endif  // BASE_LOGGING_H_
