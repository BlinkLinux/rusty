// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/base/log_manager.h"

#include <QCoreApplication>
#include <QDir>

#include "rusty/base/file.h"
#include "rusty/third_party/CuteLogger/include/ConsoleAppender.h"
#include "rusty/third_party/CuteLogger/include/FileAppender.h"
#include "rusty/third_party/CuteLogger/include/Logger.h"
#include "rusty/third_party/CuteLogger/include/RollingFileAppender.h"

namespace rusty {
namespace {

LogManager* g_instance_ = nullptr;
constexpr const int kDefaultFileLimits = 7;

}  // namespace

struct LogManagerPrivate {
  QString log_path{};
  QString log_format{};
  ConsoleAppender* console_appender{nullptr};
  RollingFileAppender* file_appender{nullptr};
};

LogManager* LogManager::instance() {
  if (g_instance_ == nullptr) {
    g_instance_ = new LogManager();
    qAddPostRoutine([]() {
      delete g_instance_;
    });
  }

  return g_instance_;
}

LogManager::LogManager() : p_(new LogManagerPrivate()) {
  QDir dir = getCacheDir();
  const QString app_name = qApp->applicationName();
  this->p_->log_path = dir.absoluteFilePath(QString("%1.log").arg(app_name));
  this->p_->log_format = "%{time}{HH:mm::ss.zzz} [%{type} %{file}:%{line}] %{message}\n";
}

LogManager::~LogManager() {
  delete this->p_;
}

void LogManager::registerConsoleLog() {
  Q_ASSERT(this->p_ != nullptr);
  if (this->p_->console_appender != nullptr) {
    cuteLoggerInstance()->removeAppender(this->p_->console_appender);
  }
  this->p_->console_appender = new ConsoleAppender();
  this->p_->console_appender->setFormat(this->p_->log_format);
  cuteLoggerInstance()->registerAppender(this->p_->console_appender);
}

void LogManager::registerFileLog() {
  this->registerFileLog(kDefaultFileLimits);
}

void LogManager::registerFileLog(int file_limit) {
  Q_ASSERT(this->p_ != nullptr);
  if (this->p_->file_appender != nullptr) {
    cuteLoggerInstance()->removeAppender(this->p_->file_appender);
  }
  this->p_->file_appender = new RollingFileAppender();
  this->p_->file_appender->setFormat(this->p_->log_format);
  this->p_->file_appender->setFileName(this->p_->log_path);
  this->p_->file_appender->setLogFilesLimit(file_limit);
  this->p_->file_appender->setDatePattern(RollingFileAppender::DailyRollover);
  cuteLoggerInstance()->registerAppender(this->p_->file_appender);
}

void LogManager::setLogFormat(const QString& format) {
  Q_ASSERT(this->p_ != nullptr);
  this->p_->log_format = format;
}

void LogManager::setLogFilepath(const QString& filepath) {
  Q_ASSERT(this->p_ != nullptr);
  this->p_->log_path = filepath;
  createParentDirs(filepath);
}

}  // namespace rusty