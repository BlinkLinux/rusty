// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_LINE_EDIT_H_
#define RUSTY_RUSTY_WIDGETS_LINE_EDIT_H_

#include <QLineEdit>

namespace rusty {

class LineEdit : public QLineEdit {
  Q_OBJECT
  Q_PROPERTY(QColor placeholderColor READ placeholderColor WRITE setPlaceholderColor)

 public:
  explicit LineEdit(QWidget* parent = nullptr);
  explicit LineEdit(const QString& text, QWidget* parent = nullptr);
  ~LineEdit() override = default;

  [[nodiscard]] const QColor& placeholderColor() const { return this->placeholder_color_; }

 public slots:
  void setPlaceholderColor(const QColor& color);

 private:
  QColor placeholder_color_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_LINE_EDIT_H_
