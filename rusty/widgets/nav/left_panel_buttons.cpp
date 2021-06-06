// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/nav/left_panel_buttons.h"

#include "rusty/widgets/nav/tab_button.h"

namespace rusty {

LeftPanelButtons::LeftPanelButtons(QWidget* parent) : QFrame(parent) {
  this->initUi();
  this->initSignals();
}

void LeftPanelButtons::initUi() {
  this->button_group_ = new QButtonGroup(this);
  this->button_layout_ = new QVBoxLayout();
  this->button_layout_->setSpacing(0);
  this->button_layout_->setContentsMargins(0, 0, 0, 0);
  this->setLayout(this->button_layout_);
}

void LeftPanelButtons::initSignals() {
  connect(this->button_group_, &QButtonGroup::idClicked, [=](int button_id) {
    emit this->activeChanged(button_id);
  });
}

QAbstractButton* LeftPanelButtons::button(int button_id) {
  return this->button_group_->button(button_id);
}

QAbstractButton* LeftPanelButtons::addButton(int button_id, const QString& icon, const QString& text) {
  auto* button = new TabButton(icon, text);
  this->button_layout_->addWidget(button);
  this->button_group_->addButton(button, button_id);
  return button;
}

void LeftPanelButtons::addStretch() {
  this->button_layout_->addStretch();
}

int LeftPanelButtons::activeId() const {
  return this->button_group_->checkedId();
}

void LeftPanelButtons::setActiveId(int button_id) {
  this->button_group_->button(button_id)->click();
}

}  // namespace rusty