// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_COLOR_CHANNEL_LINE_EDIT_H_
#define RUSTY_RUSTY_WIDGETS_COLOR_CHANNEL_LINE_EDIT_H_

#include "rusty/widgets/line_edit.h"

namespace rusty {

class ColorChannelLineEdit : public LineEdit {
  Q_OBJECT
  Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

 public:
  explicit ColorChannelLineEdit(QWidget* parent = nullptr);
  ~ColorChannelLineEdit() override = default;

  [[nodiscard]] int value() const;

 public slots:
  void setValue(int value);

 signals:
  void valueChanged(int value);

 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private slots:
  void onTextChanged();
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_COLOR_CHANNEL_LINE_EDIT_H_
