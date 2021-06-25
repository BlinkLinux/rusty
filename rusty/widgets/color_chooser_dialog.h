// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_DIALOG_H_
#define RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_DIALOG_H_

#include <QDialog>

#include "rusty/widgets/color_chooser_widget.h"

namespace rusty {

class ColorChooserDialog : public QDialog {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

 public:
  explicit ColorChooserDialog(QWidget* parent = nullptr);
  ~ColorChooserDialog() override = default;

  void setColorPalette(const ColorPalette& palette) {
    this->color_widget_->setColorPalette(palette);
  }

  [[nodiscard]] const QColor& color() const {
    return this->color_widget_->color();
  }

 public slots:
  void setColor(const QColor& color) {
   this->color_widget_->setColor(color);
 };

 signals:
  void colorChanged(const QColor& color);

 private:
  void initUi();

  void initSignals();

  ColorChooserWidget* color_widget_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_DIALOG_H_
