// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/widgets/color_channel_label.h"

#include <QDebug>
#include <QFont>

namespace rusty {

ColorChannelLabel::ColorChannelLabel(const QString& text, QWidget* parent) : QLabel(text, parent) {
  QFont font(this->font());
  font.setPixelSize(10);
  this->setFont(font);
}

}  // namespace rusty