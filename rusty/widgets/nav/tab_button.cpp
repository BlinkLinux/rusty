// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/nav/tab_button.h"

#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include <rusty/widgets/theme_manager.h>

namespace rusty {

TabButton::TabButton(const QString& icon_name, const QString& text, QWidget* parent)
    : QPushButton(text, parent),
      pixmap_(icon_name) {
  this->setFlat(true);
  this->setCheckable(true);
  this->setFixedSize(51, 51);

  rusty::ThemeManager::instance().registerWidget(this, icon_name, [=](bool changed, const QString& new_icon_name) {
    if (changed) {
      this->pixmap_.load(new_icon_name);
      this->update();
    }
  });
}

void TabButton::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)
  QPainter painter(this);

  // Fill selected background.
  if (this->isChecked()) {
    const QColor bg_color = this->palette().color(QPalette::Window);
    painter.fillRect(this->rect(), bg_color);
  } else {
    painter.setOpacity(0.6f);
  }

  const int pixmap_x = (this->width() - this->pixmap_.width()) / 2;
  constexpr int kPixmapMargin = 8;
  painter.drawPixmap(pixmap_x, kPixmapMargin, this->pixmap_);

  constexpr int kTextTopMargin = 6;
  const QRect text_rect = this->rect().marginsRemoved(
      QMargins(0, kPixmapMargin + kTextTopMargin + pixmap_.height(), 0, 0));
  constexpr int kTextFlags = Qt::AlignHCenter;
  QFont font(painter.font());
  font.setPixelSize(9);
  painter.setFont(font);
  QPen pen(painter.pen());
  const QColor text_color = this->palette().color(QPalette::BrightText);
  pen.setColor(text_color);
  painter.setPen(pen);
  painter.drawText(text_rect, kTextFlags, this->text());
}

}  // namespace rusty