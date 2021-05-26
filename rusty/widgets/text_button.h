// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_TEXT_BUTTON_H_
#define RUSTY_RUSTY_WIDGETS_TEXT_BUTTON_H_

#include <QLabel>

namespace rusty {

class TextButton : public QLabel {
  Q_OBJECT
  Q_PROPERTY(bool activated READ activated WRITE setActivated)
  Q_PROPERTY(int index READ index WRITE setIndex)
 public:
  explicit TextButton(QWidget* parent = nullptr);

  explicit TextButton(const QString& text, QWidget* parent = nullptr);

  ~TextButton() override = default;

  [[nodiscard]] bool activated() const { return this->activated_; }

  [[nodiscard]] int index() const { return this->index_; }

 public slots:
  void setActivated(bool activated);

  void setIndex(int index);

 signals:
  void clicked();

 protected:
  void mousePressEvent(QMouseEvent* ev) override;

  void enterEvent(QEvent* event) override;

  void leaveEvent(QEvent* event) override;

 private:
  bool activated_{true};
  int index_{0};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_TEXT_BUTTON_H_
