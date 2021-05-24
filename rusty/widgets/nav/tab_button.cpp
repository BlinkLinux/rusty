// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/nav/tab_button.h"

#include <QDebug>
#include <QPainter>
#include <QPainterPath>

namespace rusty {

TabButton::TabButton(const QString& icon_path, const QString& text, QWidget* parent)
    : QPushButton(text, parent),
      icon_path_(icon_path),
      pixmap_(icon_path),
      checked_color_(QColor("#383f47")) {
  this->setFlat(true);
  this->setCheckable(true);
  this->setFixedSize(51, 51);
}

void TabButton::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)
  QPainter painter(this);

  // Fill selected background.
  if (this->isChecked()) {
    painter.fillRect(this->rect(), this->checked_color_);
  } else {
    painter.setOpacity(0.6f);
  }

  const int pixmap_x = (this->width() - this->pixmap_.width()) / 2;
  constexpr int kPixmapMargin = 8;
  painter.drawPixmap(pixmap_x, kPixmapMargin, this->pixmap_);

  constexpr int kTextTopMargin = 6;
  const QRect text_rect = this->rect().marginsRemoved(
      QMargins(0, kPixmapMargin + kTextTopMargin + pixmap_.height(), 0, 0));
  const int text_flags = Qt::AlignHCenter;
  QFont font(painter.font());
  font.setPixelSize(9);
  painter.setFont(font);
  QPen pen(painter.pen());
  pen.setColor(Qt::white);
  painter.setPen(pen);
  painter.drawText(text_rect, text_flags, this->text());
}

void TabButton::setCheckedColor(const QColor& color) {
  this->checked_color_ = color;
  this->update();
}

}  // namespace rusty