// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_NAV_TAB_BUTTON_H_
#define RUSTY_RUSTY_WIDGETS_NAV_TAB_BUTTON_H_

#include <QPushButton>

namespace rusty {

class TabButton : public QPushButton {
  Q_OBJECT
  Q_PROPERTY(QColor checkedColor READ checkedColor WRITE setCheckedColor)
 public:
  TabButton(const QString& icon_path, const QString& text, QWidget* parent = nullptr);

  [[nodiscard]] const QColor& checkedColor() const { return this->checked_color_; }

 public slots:
  void setCheckedColor(const QColor& color);

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  QString icon_path_;
  QPixmap pixmap_;
  QColor checked_color_;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_NAV_TAB_BUTTON_H_
