// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/formats/color_palette.h"

#include <QJsonArray>
#include <QJsonDocument>

#include "rusty/base/file.h"
#include "rusty/gui/color.h"

namespace rusty {

ColorPalette parseColorPalette(const QString& json_file, bool* ok) {
  Q_ASSERT(ok != nullptr);
  ColorPalette palette;
  *ok = true;

  const QByteArray bytes = rusty::readBinaryFile(json_file);
  if (bytes.isEmpty()) {
    qWarning() << "Failed to open file:" << json_file;
    *ok = false;
    return palette;
  }

  const QJsonDocument document = QJsonDocument::fromJson(bytes);
  if (!document.isArray()) {
    *ok = false;
    return palette;
  }

  const QJsonArray array = document.array();
  for (const QJsonValue& value : array) {
    const QColor color = rusty::parseColor(value.toString());
    palette.append(color);
  }

  return palette;
}

}  // namespace rusty