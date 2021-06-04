// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include <QApplication>
#include <rusty/base/log_manager.h>
#include <rusty/widgets/adwaita_style.h>

#include "internal/widgets_window.h"

int main(int argc, char** argv) {
  QApplication application(argc, argv);
  rusty::LogManager::instance()->registerConsoleLog();
  QApplication::setStyle(new rusty::AdwaitaStyle(true));

  rusty::WidgetsWindow window;
  window.resize(960, 640);
  window.show();

  return QApplication::exec();
}