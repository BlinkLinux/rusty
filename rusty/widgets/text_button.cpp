// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/text_button.h"

#include <QCursor>
#include <QStyle>

namespace rusty {

TextButton::TextButton(QWidget* parent) : QLabel(parent) {
  this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->setContentsMargins(3, 2, 3, 2);
}

TextButton::TextButton(const QString& text, QWidget* parent) : TextButton(parent) {
  this->setText(text);
}

void TextButton::mousePressEvent(QMouseEvent* ev) {
  QLabel::mousePressEvent(ev);
  emit this->clicked();
}

void TextButton::enterEvent(QEvent* event) {
  QWidget::enterEvent(event);
  this->setCursor(QCursor(Qt::PointingHandCursor));
}

void TextButton::leaveEvent(QEvent* event) {
  QWidget::leaveEvent(event);
  this->unsetCursor();
}

void TextButton::setActivated(bool activated) {
  this->activated_ = activated;
  QFont font(this->font());
  font.setPixelSize(activated ? 12 : 10);
  font.setWeight(activated ? QFont::Bold : QFont::Light);
  this->setFont(font);
  this->update();
}

void TextButton::setIndex(int index) {
  this->index_ = index;
}

}  // namespace rusty