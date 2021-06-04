// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_FRAMES_SOFTWARE_LICENSE_WINDOW_H_
#define RUSTY_RUSTY_FRAMES_SOFTWARE_LICENSE_WINDOW_H_

#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "rusty/frames/models/software_license_model.h"

namespace rusty {

class SoftwareLicenseWindow : public QWidget {
  Q_OBJECT
 public:
  explicit SoftwareLicenseWindow(QWidget* parent = nullptr);
  ~SoftwareLicenseWindow() override = default;

  void setLicenseFile(const QString& file);

 signals:
  void requestOpenUrl(const QString& url);

 private slots:
  void onItemClicked(const QModelIndex& index);

 private:
  void initUi();
  void initSignals();

  QTableView* table_view_{nullptr};
  SoftwareLicenseModel* model_{nullptr};
  QPushButton* close_button_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_FRAMES_SOFTWARE_LICENSE_WINDOW_H_
