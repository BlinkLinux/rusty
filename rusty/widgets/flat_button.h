// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_FLAT_BUTTON_H_
#define RUSTY_RUSTY_WIDGETS_FLAT_BUTTON_H_

#include <QPushButton>

namespace rusty {

class FlatButton : public QPushButton {
  Q_OBJECT
 public:
  explicit FlatButton(const QString& text, QWidget* parent = nullptr);
  ~FlatButton() override = default;

  void setPixmap(const QString& icon_path);

 private:
  QString icon_path_{};
  QPixmap pixmap_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_FLAT_BUTTON_H_
