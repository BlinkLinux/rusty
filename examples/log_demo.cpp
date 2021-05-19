// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <rusty/base/log_manager.h>

int main(int argc, char** argv) {
  QCoreApplication application(argc, argv);
  rusty::LogManager::instance()->registerConsoleLog();
  qDebug() << "Debug message";
  qInfo() << "Info message";
  qWarning() << "Warning message";
  qCritical() << "Critical message";

  return QCoreApplication::exec();
}