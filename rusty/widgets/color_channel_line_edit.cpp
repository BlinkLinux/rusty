// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/widgets/color_channel_line_edit.h"

#include <QFont>
#include <QIntValidator>
#include <QKeyEvent>
#include <QPainter>

namespace rusty {
namespace {

constexpr int kMinValue = 0;
constexpr int kMaxValue = 255;

}  // namespace

ColorChannelLineEdit::ColorChannelLineEdit(QWidget* parent) : LineEdit(parent) {
  this->setMaximumWidth(36);
  QFont font(this->font());
  font.setPixelSize(12);
  font.setWordSpacing(10);
  this->setFont(font);

  auto* validator = new QIntValidator(kMinValue, kMaxValue, this);
  this->setValidator(validator);

  connect(this, &ColorChannelLineEdit::editingFinished,
          this, &ColorChannelLineEdit::onTextChanged);
}

int ColorChannelLineEdit::value() const {
  return text().toInt();
}

void ColorChannelLineEdit::setValue(int value) {
  QSignalBlocker blocker(this);
  this->setText(QString::number(value));
}

void ColorChannelLineEdit::onTextChanged() {
  emit this->valueChanged(this->value());
}

void ColorChannelLineEdit::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Up: {
      const int new_value = this->value() + 1;
      if (new_value <= kMaxValue) {
        this->setValue(new_value);
        emit this->valueChanged(new_value);
      }
      break;
    }
    case Qt::Key_Down: {
      const int new_value = this->value() - 1;
      if (new_value >= kMinValue) {
        this->setValue(new_value);
        emit this->valueChanged(new_value);
      }
      break;
    }
    default: {
      QLineEdit::keyPressEvent(event);
    }
  }
}

}  // namespace rusty