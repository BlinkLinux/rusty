// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "rusty/base/crash_reporter.h"

#include <QDebug>
#include <QDir>

#include <common/windows/string_utils-inl.h>
#include <client/windows/handler/exception_handler.h>

namespace rusty {
namespace {

bool onDumpCallback(const wchar_t* dump_path,
                    const wchar_t* dump_id,
                    void* context,
                    EXCEPTION_POINTERS* exinfo,
                    MDRawAssertionInfo* assertion,
                    bool succeeded) {
  Q_UNUSED(dump_path)
  Q_UNUSED(dump_id)
  Q_UNUSED(exinfo)
  Q_UNUSED(assertion)

  // TODO(Shaohua): Upload dumped file to server.
  auto* crash_reporter = static_cast<CrashReporter*>(context);
  Q_UNUSED(crash_reporter);

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

  QDir dir(path);
  if (!dir.exists()) {
    if (!dir.mkpath(".")) {
      qCritical() << Q_FUNC_INFO << "Failed to create folder:" << path;
    }
  }

  const std::string path_str(path.toStdString());
  std::wstring path_ws;
  google_breakpad::WindowsStringUtils::safe_mbstowcs(path_str, &path_ws);
  p_->exception_handler = new google_breakpad::ExceptionHandler(
      path_ws,
      nullptr,
      onDumpCallback,
      this,
      google_breakpad::ExceptionHandler::HANDLER_ALL);
}

}  // namespace rusty
