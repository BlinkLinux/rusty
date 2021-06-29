// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/widgets/line_edit.h"

namespace rusty {

LineEdit::LineEdit(QWidget* parent) : QLineEdit(parent) {

}

LineEdit::LineEdit(const QString& text, QWidget* parent) : QLineEdit(text, parent) {

}

void LineEdit::setPlaceholderColor(const QColor& color) {
  this->placeholder_color_ = color;
  QPalette palette = this->palette();
  palette.setColor(QPalette::PlaceholderText, color);
  this->setPalette(palette);
  this->update();
}

}  // namespace rusty