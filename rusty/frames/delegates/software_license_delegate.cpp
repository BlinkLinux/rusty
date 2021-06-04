// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/frames/delegates/software_license_delegate.h"

#include <QFont>
#include <QPainter>
#include <QPen>

#include "rusty/frames/models/software_license_model.h"

namespace rusty {

SoftwareLicenseDelegate::SoftwareLicenseDelegate(QObject* parent) : QStyledItemDelegate(parent) {

}

void SoftwareLicenseDelegate::paint(QPainter* painter,
                                    const QStyleOptionViewItem& option,
                                    const QModelIndex& index) const {
  painter->save();

  QFont font(painter->font());
  QPen pen(painter->pen());
  constexpr int kTextFlags = Qt::AlignLeft | Qt::AlignVCenter;
  const bool is_hover = (option.state & QStyle::State_MouseOver) != 0;
  constexpr const int kLeftMargin = 12;
  const QRect rect = option.rect.marginsRemoved(QMargins{kLeftMargin, 0, 0, 0});

  if (index.column() == SoftwareLicenseModel::kSoftwareColumn) {
    const QString name = index.data(SoftwareLicenseModel::kNameRole).toString();
    const QString url = index.data(SoftwareLicenseModel::kUrlRole).toString();
    if (!url.isEmpty()) {
      pen.setColor(option.palette.color(QPalette::Link));
    }

    painter->setPen(pen);
    if (is_hover) {
      font.setUnderline(true);
      painter->setFont(font);
    }
    QRect bounding_rect{};
    painter->drawText(rect, kTextFlags, name, &bounding_rect);

    const QString version = index.data(SoftwareLicenseModel::kVersionRole).toString();
    constexpr const int kVersionLeftMargin = 8;
    pen.setColor(option.palette.color(QPalette::Text));
    painter->setPen(pen);
    font.setUnderline(false);
    painter->setFont(font);
    painter->drawText(bounding_rect.x() + bounding_rect.width() + kVersionLeftMargin, rect.y(),
                      rect.width() - bounding_rect.width(), rect.height(),
                      kTextFlags, version);
  } else if (index.column() == SoftwareLicenseModel::kLicenseColumn) {
    const QString license = index.data(SoftwareLicenseModel::kLicenseRole).toString();
    const QString license_url = index.data(SoftwareLicenseModel::kLicenseUrlRole).toString();
    if (!license_url.isEmpty()) {
      pen.setColor(option.palette.color(QPalette::Link));
    }
    painter->setPen(pen);
    if (is_hover) {
      font.setUnderline(true);
      painter->setFont(font);
    }
    painter->drawText(rect, kTextFlags, license);
  }

  painter->restore();
}

}  // namespace rusty