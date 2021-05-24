// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include <QApplication>

#include "demo/widgets_window.h"

int main(int argc, char** argv) {
  QApplication application(argc, argv);

  rusty::WidgetsWindow window;
  window.show();

  return QApplication::exec();
}