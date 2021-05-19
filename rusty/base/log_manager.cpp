// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
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
  this->p_->log_format = "%{time}{yyyy-MM-dd HH:mm::ss.zzz} [%{type:-7}] [%{file:-16} "
                "%{function:-30} %{line}] %{message}\n";
}

LogManager::~LogManager() {
  delete this->p_;
}

}  // namespace rusty