// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/menu_row_actions.h"

#include <QHBoxLayout>
#include <QPushButton>

#include "rusty/widgets/icon_button.h"

namespace rusty {

MenuRowActions::MenuRowActions(QObject* parent) : QWidgetAction(parent) {
  this->button_container_ = new QWidget();
  auto* layout = new QHBoxLayout();
  this->button_container_->setLayout(layout);
}

void MenuRowActions::addButton(const QString& icon_path, int button_id) {
  auto* icon_button = new IconButton(icon_path);
  this->button_container_->layout()->addWidget(icon_button);
  connect(icon_button, &IconButton::clicked,
          this, &MenuRowActions::trigger);
  connect(icon_button, &IconButton::clicked, [=]() {
    emit this->buttonClicked(button_id);
  });
}

QWidget* MenuRowActions::createWidget(QWidget* parent) {
  this->button_container_->setParent(parent);
  return this->button_container_;
}

void MenuRowActions::deleteWidget(QWidget* widget) {
  QWidgetAction::deleteWidget(widget);
}

}  // namespace rusty