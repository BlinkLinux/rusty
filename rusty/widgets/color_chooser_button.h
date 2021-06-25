// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_BUTTON_H
#define RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_BUTTON_H

#include <QWidget>

namespace rusty {

class ColorChooserButton : public QWidget {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor)

 public:
  explicit ColorChooserButton(QWidget* parent = nullptr);

  [[nodiscard]] const QColor& color() const { return this->color_; }

 public slots:
  void setColor(const QColor& color);

 signals:
  void clicked();

 protected:
  void paintEvent(QPaintEvent* event) override;

  void mousePressEvent(QMouseEvent* e) override;

  void enterEvent(QEvent* event) override;

  void leaveEvent(QEvent* event) override;

 private:
  QColor color_;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_COLOR_CHOOSER_BUTTON_H
