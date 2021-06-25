// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_COLOR_PALETTE_LIST_VIEW_H_
#define RUSTY_RUSTY_COLOR_PALETTE_LIST_VIEW_H_

#include <QListView>

#include "rusty/formats/color_palette.h"
#include "rusty/widgets/models/color_palette_model.h"

namespace rusty {

class ColorPaletteListView : public QListView {
  Q_OBJECT
 public:
  explicit ColorPaletteListView(QWidget* parent = nullptr);
  ~ColorPaletteListView() override = default;

  void setColorPalette(const ColorPalette& palette);

 signals:
  void colorChanged(const QColor& color);

 private slots:
  void onItemClicked(const QModelIndex& index);

 private:
  void initUi();
  void initSignals();

  ColorPaletteModel* model_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_COLOR_PALETTE_LIST_VIEW_H_
