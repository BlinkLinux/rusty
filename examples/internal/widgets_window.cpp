// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "internal/widgets_window.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QVBoxLayout>
#include <rusty/widgets/nav/nav_bar.h>
#include <rusty/widgets/menu_row_actions.h>
#include <rusty/widgets/grayscale_effect.h>

#include "internal/custom_style.h"
#include "resources/resources.h"

namespace rusty {

WidgetsWindow::WidgetsWindow(QWidget* parent) : QTabWidget(parent) {
  this->initLogTab();
  this->initMenuTab();
  this->initNavBarTab();
  this->initPopupTab();
  this->initGrayscaleTab();
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
  menu->addAction(QIcon(kResourcesComboBoxUpArrow), "Up");
  menu->addAction(QIcon(kResourcesComboBoxDownArrow), "Down");

//  auto* custom_style = new CustomStyle(false);
//  menu->setStyle(custom_style);
  menu->setStyleSheet("QMenu::icon {padding-left: 35px;}");
}


void WidgetsWindow::initNavBarTab() {
  auto* tab = new QWidget();
  this->addTab(tab, "NavBar");
  auto* main_layout = new QVBoxLayout();
  tab->setLayout(main_layout);

  auto* nav_bar = new NavBar();
  connect(nav_bar, &NavBar::levelChanged, [](int level) {
    qDebug() << "level changed:" << level;
  });
  main_layout->addWidget(nav_bar);

  auto* content_box = new QHBoxLayout();
  main_layout->addLayout(content_box);

  auto* edit = new QLineEdit();
  content_box->addWidget(edit);

  auto* add_button = new QPushButton("Add Tab");
  content_box->addWidget(add_button);
  connect(add_button, &QPushButton::clicked, [=]() {
    const QString text = edit->text();
    if (!text.isEmpty()) {
      nav_bar->pushTab(text);
    }
  });

  auto* clear_button = new QPushButton("Clear Tabs");
  content_box->addWidget(clear_button);
  connect(clear_button, &QPushButton::clicked, [=]() {
    nav_bar->clearTabs();
  });
}

void WidgetsWindow::initPopupTab() {
  auto* tab = new QWidget();
  this->addTab(tab, "Popup");
  auto* main_layout = new QVBoxLayout();
  tab->setLayout(main_layout);

  auto* open_button = new QPushButton(tr("Open"));
  main_layout->addWidget(open_button);

  auto* menu = new QMenu();
  open_button->setMenu(menu);
  auto* menu_layout = new QVBoxLayout();
  menu->setLayout(menu_layout);

  menu_layout->addWidget(new QLabel("Item 1"));
  menu_layout->addWidget(new QLabel("Item 2"));
  menu_layout->addWidget(new QLabel("Item 3"));
  menu_layout->addWidget(new QPushButton("Click me"));

  auto* text_button = new QPushButton("Texts");
  main_layout->addWidget(text_button);
  auto* text_menu = new QMenu();
  text_button->setMenu(text_menu);
  auto* row1 = new MenuRowActions();
  row1->addButton(kResourcesComboBoxUpArrow, 0);
  row1->addButton(kResourcesComboBoxDropDown, 1);
  row1->addButton(kResourcesComboBoxDownArrow, 2);
  connect(row1, &MenuRowActions::buttonClicked, [](int button_id) {
    qDebug() << "menu row button clicked with id: " << button_id;
  });
  text_menu->addAction(row1);
  auto* row2 = new MenuRowActions();
  text_menu->addAction(row2);
  text_menu->addAction("Item 2");
  text_menu->addAction("Item 3");
}

void WidgetsWindow::initGrayscaleTab() {
  auto* tab = new QWidget();
  this->addTab(tab, "Grayscale");
  auto* main_layout = new QVBoxLayout();
  tab->setLayout(main_layout);

  auto* img = new QLabel();
  img->setPixmap(QPixmap(kResourcesReceptor));
  main_layout->addWidget(img);
  auto* grayscale_effect = new GrayscaleEffect(this);
  grayscale_effect->setEnabled(false);
  img->setGraphicsEffect(grayscale_effect);

  auto* button = new QPushButton("Toggle grayscale");
  button->setCheckable(true);
  connect(button, &QPushButton::toggled,
          grayscale_effect, &GrayscaleEffect::setEnabled);
  main_layout->addWidget(button);
}

}  // namespace rusty