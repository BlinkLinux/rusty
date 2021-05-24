// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "internal//custom_style.h"

namespace rusty {

CustomStyle::CustomStyle(bool dark) : AdwaitaStyle(dark) {

}

int CustomStyle::pixelMetric(QStyle::PixelMetric metric, const QStyleOption* option, const QWidget* widget) const {
  switch (metric) {
    case QStyle::PM_SmallIconSize: {
      return 46;
    }
    case QStyle::PM_MenuHMargin: {
      return 4;
    }
    default: {
      return AdwaitaStyle::pixelMetric(metric, option, widget);
    }
  }
}

}  // namespace rusty