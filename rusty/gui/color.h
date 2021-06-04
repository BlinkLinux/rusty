// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_GUI_COLOR_H_
#define RUSTY_RUSTY_GUI_COLOR_H_

#include <QColor>
#include <QString>

namespace rusty {

QColor parseColor(QString val);

QColor randomColor();

}  // namespace rusty

#endif  // RUSTY_RUSTY_GUI_COLOR_H_
