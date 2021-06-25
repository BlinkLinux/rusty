// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_FRAMES_COLOR_CHOOSER_WINDOW_H_
#define RUSTY_RUSTY_FRAMES_COLOR_CHOOSER_WINDOW_H_

#include <QStackedLayout>
#include <QWidget>

#include "rusty/formats/color_palette.h"
#include "rusty/widgets/color_channel_label.h"
#include "rusty/widgets/color_channel_line_edit.h"
#include "rusty/widgets/color_line_edit.h"
#include "rusty/widgets/color_palette_list_view.h"
#include "rusty/widgets/flat_button.h"
#include "rusty/widgets/hsv_color_picker.h"

namespace rusty {

class ColorChooserWindow : public QFrame {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
 public:
  explicit ColorChooserWindow(QWidget* parent = nullptr);

  void setGradientVisible(bool visible);

  void setEnableTransparent(bool enable);

  void setSolidColorPalette(const ColorPalette& palette);

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
  void initSolidColor();
  void initGradient();

  void initSignals();

  QStackedLayout* stacked_layout_{nullptr};

  QWidget* button_container_{nullptr};
  FlatButton* solid_button_{nullptr};
  FlatButton* gradient_button_{nullptr};

  QWidget* solid_page_{nullptr};
  QColor solid_color_{};
  ColorPaletteListView* color_palette_list_view_{nullptr};
  FlatButton* color_chooser_button_{nullptr};
  FlatButton* transparent_button_{nullptr};
  HSVColorPicker* color_picker_{nullptr};
  ColorLineEdit* color_line_edit_{nullptr};
  ColorChannelLineEdit* r_line_edit_{nullptr};
  ColorChannelLineEdit* g_line_edit_{nullptr};
  ColorChannelLineEdit* b_line_edit_{nullptr};
  ColorChannelLineEdit* a_line_edit_{nullptr};

  QWidget* gradient_page_{nullptr};

  ColorChannelLabel* a_label_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_FRAMES_COLOR_CHOOSER_WINDOW_H_
