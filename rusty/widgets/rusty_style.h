// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_RUSTY_STYLE_H_
#define RUSTY_RUSTY_WIDGETS_RUSTY_STYLE_H_

#include <QProxyStyle>

namespace rusty {

class RustyStyle : public QProxyStyle {
  Q_OBJECT

 public:
  explicit RustyStyle(QStyle* style = nullptr);
  ~RustyStyle() override = default;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_RUSTY_STYLE_H_
