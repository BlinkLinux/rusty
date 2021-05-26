// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/icon_button.h"

#include <QDebug>
#include <QPainter>

#include "rusty/widgets/theme_manager.h"

namespace rusty {
namespace {

constexpr const int kMargins = 8;

}  // namespace

IconButton::IconButton(const QString& icon_name, QWidget* parent)
    : QPushButton(parent),
      pixmap_(icon_name) {
  this->setFlat(true);
  this->setFixedSize(this->pixmap_.size().width() + kMargins,
                     this->pixmap_.size().height() + kMargins);
  auto& manager = rusty::ThemeManager::instance();
  manager.registerWidget(this, icon_name, [this](bool changed, const QString& new_icon) {
    if (changed) {
      this->pixmap_.load(new_icon);
      this->update();
    }
  });
}

void IconButton::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)
  QPainter painter(this);

  // Draw border
  if (this->underMouse()) {
    const auto theme_type = rusty::ThemeManager::instance().themeType();
    const auto role = (theme_type == rusty::ThemeManager::kDarkTheme) ? QPalette::Midlight : QPalette::Mid;
    const QColor bg_color = this->palette().color(role);
    painter.fillRect(this->rect(), bg_color);
  }
  const int x = (this->width() - this->pixmap_.width()) / 2;
  const int y = (this->height() - this->pixmap_.height()) / 2;
  painter.drawPixmap(x, y, this->pixmap_);
}

}  // namespace rusty