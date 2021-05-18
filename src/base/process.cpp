// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "base/process.h"

#include <QDebug>
#include <QProcess>

namespace rusty {

bool getCommandOutput(const QString& cmd, QString& output) {
  return getCommandOutput(cmd, {}, output);
}

bool getCommandOutput(const QString& cmd, const QStringList& args, QString& output) {
  QProcess process;
  process.setProgram(cmd);
  process.setArguments(args);
  process.start();
  process.waitForFinished();
  const bool ok = (process.exitStatus() == QProcess::ExitStatus::NormalExit && process.exitCode() == 0);
  if (ok) {
    output = process.readAllStandardOutput();
  } else {
    qWarning() << process.readAllStandardError();
  }
  return ok;
}

}  // namespace rusty