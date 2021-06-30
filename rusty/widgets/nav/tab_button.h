// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_NAV_TAB_BUTTON_H_
#define RUSTY_RUSTY_WIDGETS_NAV_TAB_BUTTON_H_

#include <QPushButton>

namespace rusty {

class TabButton : public QPushButton {
  Q_OBJECT

 public:
  TabButton(const QString& icon_name, const QString& text, QWidget* parent = nullptr);
  ~TabButton() override = default;

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  QPixmap pixmap_;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_NAV_TAB_BUTTON_H_
