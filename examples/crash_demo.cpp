// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <rusty/base/crash_reporter.h>

int main(int argc, char** argv) {
  rusty::CrashReporter reporter;
  reporter.setDumpDir("/tmp/crash-demo");

  QCoreApplication application(argc, argv);

  qDebug() << "Will crash in 2000 ms";
  QTimer::singleShot(2000, []() {
    rusty::raiseSegmentFault();
  });

  return QCoreApplication::exec();
}