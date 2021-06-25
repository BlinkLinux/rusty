// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef PUBLISHER_SRC_FRAMES_DELEGATES_COLOR_PALETTE_DELEGATE_H_
#define PUBLISHER_SRC_FRAMES_DELEGATES_COLOR_PALETTE_DELEGATE_H_

#include <QStyledItemDelegate>

namespace publisher {

class ColorPaletteDelegate : public QStyledItemDelegate{
  Q_OBJECT
 public:
  explicit ColorPaletteDelegate(QObject* parent = nullptr);

  void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

  [[nodiscard]] QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;

  static const int kWidthHint = 24;
  static const int kHeightHint = 24;
};

}  // namespace publisher

#endif  // PUBLISHER_SRC_FRAMES_DELEGATES_COLOR_PALETTE_DELEGATE_H_
