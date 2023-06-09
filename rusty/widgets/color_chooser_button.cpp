// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/widgets/color_chooser_button.h"

#include <QDebug>
#include <QPainter>
#include <QPainterPath>

#include "rusty/widgets/color_chooser_dialog.h"

namespace rusty {

ColorChooserButton::ColorChooserButton(QWidget* parent) : QWidget(parent) {

}

void ColorChooserButton::setColor(const QColor& color) {
  this->color_ = color;
  emit this->colorChanged(color);
  this->update();
}

void ColorChooserButton::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)
  QPainter painter(this);
  painter.setRenderHints(QPainter::Antialiasing);
  QPainterPath path;
  path.addRoundedRect(this->rect(), 4.3, 4.3);
  QPen pen;
  pen.setWidthF(0.3);
  pen.setColor(QColor(0, 0, 0));
  painter.setPen(pen);
  painter.fillPath(path, this->color_);
  painter.drawPath(path);
}

void ColorChooserButton::mousePressEvent(QMouseEvent* event) {
  Q_UNUSED(event)
  auto* dialog = new ColorChooserDialog();
  dialog->setModal(true);
  if (this->palette_changed_) {
    dialog->setColorPalette(this->palette_);
  }
  dialog->setColor(this->color_);
  connect(dialog, &ColorChooserDialog::colorChanged,
          this, &ColorChooserButton::setColor);
  connect(dialog, &ColorChooserDialog::finished,
          dialog, &ColorChooserDialog::deleteLater);
  dialog->exec();
}

QSize ColorChooserButton::sizeHint() const {
  return {64, 24};
}

}  // namespace rusty