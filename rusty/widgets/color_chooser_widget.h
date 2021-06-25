// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_FRAMES_COLOR_CHOOSER_WINDOW_H_
#define RUSTY_RUSTY_FRAMES_COLOR_CHOOSER_WINDOW_H_

#include <QWidget>

#include "rusty/formats/color_palette.h"
#include "rusty/widgets/color_channel_label.h"
#include "rusty/widgets/color_channel_line_edit.h"
#include "rusty/widgets/color_line_edit.h"
#include "rusty/widgets/color_palette_list_view.h"
#include "rusty/widgets/hsv_color_picker.h"

namespace rusty {

class ColorChooserWidget : public QWidget {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
 public:
  explicit ColorChooserWidget(QWidget* parent = nullptr);
  ~ColorChooserWidget() override = default;

  void setEnableTransparent(bool enable);

  void setColorPalette(const ColorPalette& palette);

  [[nodiscard]] const QColor& color() const { return this->solid_color_; }

 public slots:
  void setColor(const QColor& color);

 signals:
  void colorChanged(const QColor& color);

  void lostFocus();

 protected:
  void focusOutEvent(QFocusEvent* event) override;

 private:
  void initUi();

  void initSignals();

  QColor solid_color_{};
  ColorPaletteListView* color_palette_list_view_{nullptr};
  HSVColorPicker* color_picker_{nullptr};
  ColorLineEdit* color_line_edit_{nullptr};
  ColorChannelLineEdit* r_line_edit_{nullptr};
  ColorChannelLineEdit* g_line_edit_{nullptr};
  ColorChannelLineEdit* b_line_edit_{nullptr};
  ColorChannelLineEdit* a_line_edit_{nullptr};
  ColorChannelLabel* a_label_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_FRAMES_COLOR_CHOOSER_WINDOW_H_
