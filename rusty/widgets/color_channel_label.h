// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_COLOR_CHANNEL_LABEL_H_
#define RUSTY_RUSTY_WIDGETS_COLOR_CHANNEL_LABEL_H_

#include <QLabel>

namespace rusty {

class ColorChannelLabel : public QLabel {
  Q_OBJECT
 public:
  explicit ColorChannelLabel(QWidget* parent = nullptr);
  explicit ColorChannelLabel(const QString& text, QWidget* parent = nullptr);
  ~ColorChannelLabel() override = default;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_COLOR_CHANNEL_LABEL_H_
