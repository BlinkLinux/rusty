// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "rusty/base/crash_reporter.h"

#include <QDebug>
#include <QDir>
#include <client/linux/handler/exception_handler.h>
#include <client/linux/handler/minidump_descriptor.h>

namespace rusty {
namespace {

bool onDumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                    void* context, bool succeeded) {
  fprintf(stderr, "Dump path: %s\n", descriptor.path());
  // TODO(Shaohua): Upload dumped file to server.
  auto* crash_reporter = static_cast<CrashReporter*>(context);
  Q_UNUSED(crash_reporter)

  return succeeded;
}

}  // namespace

struct CrashReporterPrivate {
  ~CrashReporterPrivate() {
    delete exception_handler;
  }

  google_breakpad::ExceptionHandler* exception_handler{nullptr};
};

CrashReporter::CrashReporter() : p_(new CrashReporterPrivate()) {
}

CrashReporter::~CrashReporter() {
  delete this->p_;
}

void CrashReporter::setDumpDir(const QString& path) {
  this->dump_dir_ = path;
  delete p_->exception_handler;

  QDir dir(this->dump_dir_);
  if (!dir.exists()) {
    if (!dir.mkpath(".")) {
      qCritical() << Q_FUNC_INFO << "Failed to create folder:" << path;
    }
  }

  const google_breakpad::MinidumpDescriptor descriptor(this->dump_dir_.toStdString());
  p_->exception_handler = new google_breakpad::ExceptionHandler(
      descriptor, nullptr, onDumpCallback, this, true, -1);
}

}  // namespace rusty