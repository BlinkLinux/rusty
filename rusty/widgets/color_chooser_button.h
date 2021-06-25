// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_BUTTON_H
#define RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_BUTTON_H

#include <QWidget>

#include "rusty/formats/color_palette.h"

namespace rusty {

class ColorChooserButton : public QWidget {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor)

 public:
  explicit ColorChooserButton(QWidget* parent = nullptr);

  [[nodiscard]] const QColor& color() const { return this->color_; }

  void setColorPalette(const ColorPalette& palette) {
    this->palette_changed_ = true;
    this->palette_ = palette;
  }

 public slots:
  void setColor(const QColor& color);

 protected:
  void paintEvent(QPaintEvent* event) override;

  void mousePressEvent(QMouseEvent* e) override;

 private:
  QColor color_;
  bool palette_changed_{false};
  ColorPalette palette_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_BUTTON_H
