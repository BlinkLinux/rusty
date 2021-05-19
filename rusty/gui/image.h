// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_GUI_IMAGE_H_
#define RUSTY_RUSTY_GUI_IMAGE_H_

#include <QImage>

namespace rusty {

QImage colorizeImage(const QImage& image, const QColor& color);

QImage colorizeImage(const QImage& image, const QColor& src_color, const QColor& dest_color);

}  // namespace rusty

#endif  // RUSTY_RUSTY_GUI_IMAGE_H_
