// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/rusty_style.h"

namespace rusty {

RustyStyle::RustyStyle(QStyle* style) : QProxyStyle(style) {

}

}  // namespace rusty