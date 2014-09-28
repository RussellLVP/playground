// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/logging.h"

namespace logging {
namespace {

// The minimum log severity in order for an entry to be created.
int g_minimum_log_severity = LOG_INFO;

// Textual names of the available logging levels, used in the created output.
const char* const g_log_severity_names[4] = {
  /* LOG_INFO */    "INFO",
  /* LOG_WARNING */ "WARNING",
  /* LOG_ERROR */   "ERROR",
  /* LOG_FATAL */   "FATAL"
};

const char* log_severity_name(int severity) {
  if (severity >= 0 && severity < 4)
    return g_log_severity_names[severity];

  return "UNKNOWN";
}

}  // namespace

LogMessage::Delegate* LogMessage::delegate_;

// static
void LogMessage::SetDelegate(Delegate* delegate) {
  delegate_ = delegate;
}

// static
void LogMessage::SetMinimumLogSeverity(int severity) {
  g_minimum_log_severity = severity;
}

// static
int LogMessage::GetMinimumLogSeverity() {
  return g_minimum_log_severity;
}

LogMessage::LogMessage(const char* file, int line, int severity) 
    : file_(file), line_(line), severity_(severity) {
  Initialize();
}

LogMessage::~LogMessage() {
  std::string message = stream_.str();
  if (!delegate_ ||
      !delegate_->WriteMessage(message)) {
    fwrite(message.data(), message.length(), 1, stderr);
    fputc('\n', stderr);

    fflush(stderr);
  }
  
  if (severity_ == LOG_FATAL)
    __debugbreak();
}

void LogMessage::Initialize() {
  std::string filename = std::string(file_);

  size_t last_slash_pos = filename.find_last_of("\\/");
  if (last_slash_pos != std::string::npos)
    filename.erase(0, last_slash_pos + 1);

  stream_ << '[' << log_severity_name(severity_) << ':';
  stream_ << filename << '(' << line_ << ")] ";
}

}  // namespace logging
