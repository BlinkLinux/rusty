// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/base/crash_reporter.h"

#include <QDebug>
#include <QDir>

#include "rusty/third_party/breakpad/src/client/linux/handler/exception_handler.h"
#include "rusty/third_party/breakpad/src/client/linux/handler/minidump_descriptor.h"

namespace rusty {
namespace {

bool onDumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                    void* context, bool succeeded) {
  Q_UNUSED(context)
  fprintf(stderr, "Dump path: %s\n", descriptor.path());
  // TODO(Shaohua): Upload dumped file to server.

  return succeeded;
}

}  // namespace

struct CrashReporterPrivate {
  ~CrashReporterPrivate() {
    delete exception_handler;
  }

  QString dump_dir{};
  google_breakpad::ExceptionHandler* exception_handler{nullptr};
};

CrashReporter::CrashReporter() : p_(new CrashReporterPrivate()) {

}

CrashReporter::~CrashReporter() {
  delete this->p_;
}

void CrashReporter::setDumpDir(const QString& path) {
  p_->dump_dir = path;
  delete p_->exception_handler;

  QDir dir(path);
  if (!dir.exists()) {
    if (!dir.mkpath(".")) {
      qCritical() << Q_FUNC_INFO << "Failed to create folder:" << path;
    }
  }

  const google_breakpad::MinidumpDescriptor descriptor(path.toStdString());
  p_->exception_handler = new google_breakpad::ExceptionHandler(
      descriptor, nullptr, onDumpCallback, this, true, -1);
}

const QString& CrashReporter::dumpDir() const {
  return this->p_->dump_dir;
}

}  // namespace rusty