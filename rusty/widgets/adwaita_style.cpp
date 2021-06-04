// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/adwaita_style.h"

namespace rusty {

AdwaitaStyle::AdwaitaStyle(bool night_mode) : Adwaita::Style(night_mode) {

}

AdwaitaStyle::~AdwaitaStyle() {

}

}  // namespace rusty