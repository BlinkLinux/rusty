// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_MODELS_COLOR_PALETTE_MODEL_H_
#define RUSTY_RUSTY_WIDGETS_MODELS_COLOR_PALETTE_MODEL_H_

#include <QAbstractListModel>

#include "rusty/formats/color_palette.h"

namespace rusty {

class ColorPaletteModel : public QAbstractListModel {
  Q_OBJECT
 public:
  explicit ColorPaletteModel(QObject* parent = nullptr);

  [[nodiscard]] int rowCount(const QModelIndex& parent) const override;

  [[nodiscard]] QVariant data(const QModelIndex& index, int role) const override;

  void setPalette(const ColorPalette& palette);

  [[nodiscard]] int items() const;

 private:
  ColorPalette palette_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_MODELS_COLOR_PALETTE_MODEL_H_
