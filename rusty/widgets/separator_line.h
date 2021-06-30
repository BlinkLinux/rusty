// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_SEPARATOR_LINE_H_
#define RUSTY_RUSTY_WIDGETS_SEPARATOR_LINE_H_

#include <QFrame>
#include <QStyleOption>

namespace rusty {

class SeparatorLine : public QFrame {
  Q_OBJECT
  Q_PROPERTY(Qt::Orientation orientation READ orientation WRITE setOrientation)

 public:
  explicit SeparatorLine(Qt::Orientation orientation, QWidget* parent = nullptr);
  ~SeparatorLine() override = default;

  [[nodiscard]] Qt::Orientation orientation() const { return this->orientation_; }

 public slots:
  void setOrientation(Qt::Orientation orientation);

 private:
  Qt::Orientation orientation_;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_SEPARATOR_LINE_H_
