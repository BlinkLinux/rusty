// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/widgets/flat_button.h"

namespace rusty {

FlatButton::FlatButton(const QString& text, QWidget* parent) : QPushButton(text, parent) {

}

void FlatButton::setPixmap(const QString& icon_path) {
  this->icon_path_ = icon_path;
  this->pixmap_ = QPixmap(this->icon_path_);
}

}  // namespace rusty