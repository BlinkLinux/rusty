// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/gui/theme_file.h"

#include <QRegularExpression>
#include <QStringList>
#include <rusty/base/file.h>

namespace rusty {
namespace {

constexpr const char* kCssPattern = R"(@CSS_IMPORT\s*"*([^"]+)\")";

bool readThemeFile(const QRegularExpression& pattern, const QString& file, QStringList& contents) {
  QString content;
  bool ok = rusty::readTextFile(file, content);
  if (!ok) {
    return false;
  }

  QStringList lines = content.split(QChar('\n'));
  for (const QString& line : lines) {
    if (line.startsWith("/*") && line.endsWith("*/")) {
      continue;
    }
    const auto match = pattern.match(line);
    if (match.hasMatch()) {
      QStringList new_lines;
      const QString theme_file = match.captured(1);
      ok = readThemeFile(pattern, theme_file, new_lines);
      if (!ok) {
        return ok;
      }
      contents.append(new_lines);
    } else {
      contents.append(line);
    }
  }

  return true;
}

}  // namespace

QString readThemeFile(const QString& file) {
  QStringList list;
  QRegularExpression pattern(kCssPattern);
  bool ok = readThemeFile(pattern, file, list);
  if (!ok) {
    return {};
  }
  return list.join(QChar('\n'));
}

}  // namespace rusty