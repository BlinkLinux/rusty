// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_FRAMES_DELEGATES_SOFTWARE_LICENSE_DELEGATE_H_
#define RUSTY_RUSTY_FRAMES_DELEGATES_SOFTWARE_LICENSE_DELEGATE_H_

#include <QStyledItemDelegate>

namespace rusty {

class SoftwareLicenseDelegate : public QStyledItemDelegate {
  Q_OBJECT
 public:
  explicit SoftwareLicenseDelegate(QObject* parent = nullptr);

  void paint(QPainter* painter, const QStyleOptionViewItem& option,
             const QModelIndex& index) const override;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_FRAMES_DELEGATES_SOFTWARE_LICENSE_DELEGATE_H_
