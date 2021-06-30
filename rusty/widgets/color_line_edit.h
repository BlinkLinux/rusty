// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_COLOR_LINE_EDIT_H
#define RUSTY_RUSTY_WIDGETS_COLOR_LINE_EDIT_H

#include "rusty/widgets/line_edit.h"

namespace rusty {

class ColorLineEdit : public LineEdit {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

 public:
  explicit ColorLineEdit(QWidget* parent = nullptr);
  ~ColorLineEdit() override = default;

  [[nodiscard]] QColor color() const;

 public slots:
  void setColor(const QColor& color);

 signals:
  void colorChanged(const QColor& color);

 private slots:
  void onTextChanged();
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_COLOR_LINE_EDIT_H
