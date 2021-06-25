// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef PUBLISHER_SRC_FRAMES_MODELS_COLOR_PALETTE_MODEL_H_
#define PUBLISHER_SRC_FRAMES_MODELS_COLOR_PALETTE_MODEL_H_

#include <QAbstractListModel>

#include "formats/color_palette.h"

namespace publisher {

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

}  // namespace publisher

#endif  // PUBLISHER_SRC_FRAMES_MODELS_COLOR_PALETTE_MODEL_H_
