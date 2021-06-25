// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_FORMATS_COLOR_PALETTE_H_
#define RUSTY_RUSTY_FORMATS_COLOR_PALETTE_H_

#include <QColor>
#include <QVector>

namespace rusty {

using ColorPalette = QVector<QColor>;

ColorPalette parseColorPalette(const QString& json_file, bool* ok);

}  // namespace rusty

#endif  // RUSTY_RUSTY_FORMATS_COLOR_PALETTE_H_
