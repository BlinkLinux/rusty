// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_HSV_COLOR_PICKER_H_
#define RUSTY_RUSTY_WIDGETS_HSV_COLOR_PICKER_H_

#include <QWidget>

namespace rusty {

class HSVColorPicker : public QWidget {
 Q_OBJECT
 Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

 public:
  explicit HSVColorPicker(QWidget* parent = nullptr);
  ~HSVColorPicker() override = default;

  const QColor& color() const { return this->color_; }

  QSize sizeHint() const override;

 public slots:
  void setColor(const QColor& color);

  void setPreviewColor(const QColor& color);

 signals:
  void colorChanged(const QColor& color);

 protected:
  void mousePressEvent(QMouseEvent* event) override;

  void mouseReleaseEvent(QMouseEvent* event) override;

  void mouseMoveEvent(QMouseEvent* event) override;

  void paintEvent(QPaintEvent* event) override;

  void resizeEvent(QResizeEvent* event) override;

 private:
  void initUi();

  void updateHue(const QPoint& pos);

  void updateSaturationValue(const QPoint& pos);

  QColor color_{};
  QRect hue_rect_{};
  QRect hue_scaled_rect_{};
  QRect sv_rect_{};
  QColor preview_color_{};
  QRect preview_rect_{};

  enum class MousePressState : uint8_t {
    kNone,
    kHuePressed,
    kSvPressed,
  };
  MousePressState mouse_press_state_{MousePressState::kNone};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_HSV_COLOR_PICKER_H_
