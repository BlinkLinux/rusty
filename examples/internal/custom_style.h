// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_EXAMPLES_INTERNAL_CUSTOM_STYLE_H_
#define RUSTY_EXAMPLES_INTERNAL_CUSTOM_STYLE_H_

#include <rusty/widgets/adwaita_style.h>

namespace rusty {

class CustomStyle : public AdwaitaStyle {
  Q_OBJECT
 public:
  explicit CustomStyle(bool dark);
  ~CustomStyle() override = default;

  int pixelMetric(PixelMetric metric, const QStyleOption* option, const QWidget* widget) const override;
};

}  // namespace rusty

#endif  // RUSTY_EXAMPLES_INTERNAL_CUSTOM_STYLE_H_
