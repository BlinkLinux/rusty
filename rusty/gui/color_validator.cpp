// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/gui/color_validator.h"

#include <QColor>

namespace rusty {

ColorValidator::ColorValidator(QObject* parent) : QValidator(parent) {

}

QValidator::State ColorValidator::validate(QString& input, int& pos) const {
  Q_UNUSED(pos)
  return QColor::isValidColor(input) ? QValidator::Acceptable : QValidator::Intermediate;
}

}  // namespace rusty