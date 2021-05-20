// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include <QApplication>
#include <QDebug>
#include <QStyleFactory>

#include "edit/code_editor.h"

int main(int argc, char** argv) {
  QApplication application(argc, argv);
  qDebug() << "available styles:" << QStyleFactory::keys();
  QApplication::setStyle("Adwaita");

  CodeEditor editor;
  editor.setWindowTitle("Code Editor Example");
  editor.show();

  return QApplication::exec();
}