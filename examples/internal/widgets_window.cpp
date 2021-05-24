// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "internal/widgets_window.h"

#include <QComboBox>
#include <QDebug>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QVBoxLayout>

#include "internal/custom_style.h"

namespace rusty {

WidgetsWindow::WidgetsWindow(QWidget* parent) : QTabWidget(parent) {
  this->initLogTab();
  this->initMenuTab();
}

void WidgetsWindow::initLogTab() {
  auto* tab = new QWidget();
  this->addTab(tab, "Log");
  auto* main_layout = new QHBoxLayout();
  tab->setLayout(main_layout);

  auto* log_level_box = new QComboBox();
  enum class LogLevel : uint8_t {
    kLogDebug,
    kInfo,
    kWarning,
    kError,
    kFatal,
  };
  struct LogStruct {
    const char* name;
    LogLevel level;
  };
  constexpr LogStruct kLogStructs[] = {
      {"Debug", LogLevel::kLogDebug},
      {"Info", LogLevel::kInfo},
      {"Warning", LogLevel::kWarning},
      {"Error", LogLevel::kError},
      {"Fatal", LogLevel::kFatal},
  };
  for (const auto& l : kLogStructs) {
    log_level_box->addItem(l.name, static_cast<uint32_t>(l.level));
  }
  main_layout->addWidget(log_level_box);
  auto* edit = new QLineEdit();
  main_layout->addWidget(edit);
  auto* button = new QPushButton("Send");
  main_layout->addWidget(button);
  connect(button, &QPushButton::clicked, [=]() {
    const QString text = edit->text();
    if (text.isEmpty()) {
      return;
    }
    const auto user_data = log_level_box->itemData(log_level_box->currentIndex(), Qt::UserRole).toUInt();
    const auto level = static_cast<LogLevel>(user_data);
    switch (level) {
      case LogLevel::kLogDebug: {
        qDebug() << text;
        break;
      }
      case LogLevel::kInfo: {
        qInfo() << text;
        break;
      }
      case LogLevel::kWarning: {
        qWarning() << text;
        break;
      }
      case LogLevel::kError: {
        qCritical() << text;
        break;
      }
      case LogLevel::kFatal: {
        qFatal("%s", text.toStdString().c_str());
        break;
      }
    }
  });
}

void WidgetsWindow::initMenuTab() {
  auto* tab = new QWidget();
  this->addTab(tab, "Custom Style");
  auto* main_layout = new QHBoxLayout();
  tab->setLayout(main_layout);

  auto* button = new QPushButton("Show Menu");
  main_layout->addWidget(button);

  auto* menu = new QMenu(this);
  button->setMenu(menu);
  menu->addAction(QIcon(":/resources/combo-box-up-arrow.svg"), "Up");
  menu->addAction(QIcon(":/resources/combo-box-down-arrow.svg"), "Down");

//  auto* custom_style = new CustomStyle(false);
//  menu->setStyle(custom_style);
  menu->setStyleSheet("QMenu::icon {padding-left: 35px;}");
}

}  // namespace rusty