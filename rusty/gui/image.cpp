// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "rusty/gui/image.h"

namespace rusty {

QImage colorizeImage(const QImage& image, const QColor& color) {
  QImage current_image(image.convertToFormat(QImage::Format_ARGB32));
  const int red = color.red();
  const int green = color.green();
  const int blue = color.blue();
  const int width = current_image.width();
  const int height = current_image.height();
  for (int y = 0; y < height; ++y) {
    QRgb* dest_row = reinterpret_cast<QRgb*>(current_image.scanLine(y));
    for (int x = 0; x < width; ++x) {
      if (qAlpha(dest_row[x]) > 0) {
        dest_row[x] = qRgba(red, green, blue, qAlpha(dest_row[x]));
      }
    }
  }
  return current_image;
}

QImage colorizeImage(const QImage& image, const QColor& src_color, const QColor& dest_color) {
  QImage current_image(image.convertToFormat(QImage::Format_ARGB32));
  const int width = current_image.width();
  const int height = current_image.height();
  for (int x = 0; x < width; ++x) {
    for (int y = 0; y < height; ++y) {
      if (src_color == current_image.pixelColor(x, y)) {
        current_image.setPixelColor(x, y, dest_color);
      }
    }
  }
  return current_image;
}

}  // namespace  rusty