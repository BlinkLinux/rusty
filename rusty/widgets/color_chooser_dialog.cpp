// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/color_chooser_dialog.h"

#include <QVBoxLayout>

namespace rusty {

ColorChooserDialog::ColorChooserDialog(QWidget* parent) : QDialog(parent) {
  this->initUi();
  this->initSignals();
  this->setWindowTitle(tr("Choose Color"));
}

void ColorChooserDialog::initUi() {
  auto* main_layout = new QVBoxLayout();
  this->setLayout(main_layout);

  this->color_widget_ = new ColorChooserWidget();
  main_layout->addWidget(this->color_widget_);
}

void ColorChooserDialog::initSignals() {
  connect(this->color_widget_, &ColorChooserWidget::colorChanged,
          this, &ColorChooserDialog::colorChanged);
}

}  // namespace rusty