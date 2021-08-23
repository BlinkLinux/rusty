// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include <gtest/gtest.h>
#include <QDebug>

#include "rusty/base/log_manager.h"

namespace rusty {

TEST(LogManager, TestDebugFormat) {
  auto manager = LogManager::instance();
  manager->setLogFormat("%{time}{yyyy-MM-ddTHH:mm::ss.zzz} [%{type} %{file}:%{line}] %{message}\n");
  manager->registerConsoleLog(LogManager::LogLevel::Debug);

  qDebug() << "Debug log";
  qInfo() << "Info log";
  qWarning() << "Warning log";
}

TEST(LogManager, TestReleaseFormat) {
  auto manager = LogManager::instance();
  manager->setLogFormat("%{time}{yyyy-MM-ddTHH:mm:ss.zzz} [%{type} %{function}] %{message}\n");
  manager->registerConsoleLog(LogManager::LogLevel::Debug);

  qDebug() << "Debug log";
  qInfo() << "Info log";
  qWarning() << "Warning log";
}

}  // namespace rusty