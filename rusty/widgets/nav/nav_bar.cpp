// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU LESSER General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/nav/nav_bar.h"

#include <QDebug>
#include <QSpacerItem>

#include "rusty/widgets/text_button.h"

namespace rusty {

NavBar::NavBar(QWidget* parent) : QFrame(parent) {
  this->initUi();
  this->setFixedHeight(51);
}

void NavBar::initUi() {
  this->main_layout_ = new QHBoxLayout();
  this->main_layout_->setContentsMargins(0, 0, 0, 0);
  this->main_layout_->setSpacing(0);
  this->setLayout(this->main_layout_);
  this->setContentsMargins(0, 0, 0, 0);

  this->main_layout_->addStretch();
}

void NavBar::pushTab(const QString& label) {
  auto* button = new TextButton(label);
  button->setIndex(this->max_level_);
  this->max_level_ += 1;
  connect(button, &TextButton::clicked, [=]() {
    const int next_level = button->index() + 1;
    while (next_level < this->main_layout_->count() - 1) {
      this->main_layout_->takeAt(next_level)->widget()->deleteLater();
    }
    this->max_level_ = button->index() + 1;
    button->setActivated(true);
    this->update();
    emit this->levelChanged(button->index());
  });

  this->main_layout_->insertWidget(this->main_layout_->count() - 1, button);

  for (int index = 0; index < this->main_layout_->count() - 2; ++index) {
    auto* other_button = qobject_cast<TextButton*>(this->main_layout_->itemAt(index)->widget());
    other_button->setActivated(false);
  }
  button->setActivated(true);
}

void NavBar::clearTabs() {
  // Remains stretch item
  while (this->main_layout_->count() != 1) {
    this->main_layout_->takeAt(0)->widget()->deleteLater();
  }
  this->max_level_ = 0;
}

}  // namespace rusty