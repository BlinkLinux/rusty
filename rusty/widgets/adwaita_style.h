// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_ADWAITA_STYLE_H_
#define RUSTY_RUSTY_WIDGETS_ADWAITA_STYLE_H_

#include "rusty/third_party/adwaita-qt/src/style/adwaitastyle.h"

namespace rusty {

// Re-export adwaita style class.
class AdwaitaStyle : public Adwaita::Style {
  Q_OBJECT

 public:
  explicit AdwaitaStyle(bool night_mode);
  ~AdwaitaStyle();

};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_ADWAITA_STYLE_H_
