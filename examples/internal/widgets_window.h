// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_EXAMPLES_INTERNAL_WIDGETS_WINDOW_H_
#define RUSTY_EXAMPLES_INTERNAL_WIDGETS_WINDOW_H_

#include <QTabWidget>

namespace rusty {

class WidgetsWindow : public QTabWidget {
  Q_OBJECT
 public:
  explicit WidgetsWindow(QWidget* parent = nullptr);
  ~WidgetsWindow() override = default;

 private:
  void initMiscTab();
  void initLogTab();
  void initMenuTab();
  void initNavBarTab();
  void initPopupTab();
  void initGrayscaleTab();
};

}  // namespace

#endif  // RUSTY_EXAMPLES_INTERNAL_WIDGETS_WINDOW_H_
