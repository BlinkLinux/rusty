// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/grayscale_effect.h"

#include <QPainter>

namespace rusty {

GrayscaleEffect::GrayscaleEffect(QObject* parent) : QGraphicsEffect(parent) {

}

void GrayscaleEffect::draw(QPainter* painter) {
  const QPixmap pixmap = this->sourcePixmap();
  QImage img = pixmap.toImage();
  const int pixels = img.width() * img.height();
  auto* data = reinterpret_cast<unsigned int*>(img.bits());
  for (int i = 0; i < pixels; ++i) {
    const int val = qGray(data[i]);
    data[i] = qRgb(val, val, val);
  }

  painter->drawImage(0, 0, img);
}

}  // namespace rusty