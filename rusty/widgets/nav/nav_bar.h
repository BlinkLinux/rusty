// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_NAV_NAV_BAR_H_
#define RUSTY_RUSTY_WIDGETS_NAV_NAV_BAR_H_

#include <QFrame>
#include <QHBoxLayout>

namespace rusty {

class NavBar : public QFrame {
  Q_OBJECT

 public:
  explicit NavBar(QWidget* parent = nullptr);
  ~NavBar() override = default;

 public slots:
  void pushTab(const QString& label);

  void clearTabs();

 signals:
  void levelChanged(int level);

 private slots:

 private:
  void initUi();

  QHBoxLayout* main_layout_{nullptr};
  int max_level_{0};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_NAV_NAV_BAR_H_
