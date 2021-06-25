// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef PUBLISHER_SRC_FRAMES_INTERNAL_COLOR_PALETTE_LIST_VIEW_H_
#define PUBLISHER_SRC_FRAMES_INTERNAL_COLOR_PALETTE_LIST_VIEW_H_

#include <QListView>

#include "formats/color_palette.h"
#include "frames/models/color_palette_model.h"

namespace publisher {

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

}  // namespace publisher

#endif  // PUBLISHER_SRC_FRAMES_INTERNAL_COLOR_PALETTE_LIST_VIEW_H_
