// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "rusty/widgets/color_chooser_window.h"

#include <QButtonGroup>
#include <QDebug>
#include <QGridLayout>

#include "rusty/widgets/separator_line.h"

namespace rusty {

ColorChooserWindow::ColorChooserWindow(QWidget* parent) : QFrame(parent) {
  this->setWindowFlags(Qt::Popup);

  this->initUi();
  this->initSignals();
}

void ColorChooserWindow::initUi() {
  auto* main_layout = new QVBoxLayout();
  main_layout->setContentsMargins(0, 0, 0, 0);
  main_layout->setSpacing(0);
  this->setLayout(main_layout);
  this->setFixedWidth(290);

  this->color_picker_ = new HSVColorPicker();
  main_layout->addWidget(this->color_picker_);

  auto* grid_layout = new QGridLayout();
  grid_layout->setContentsMargins(0, 0, 0, 0);
  grid_layout->setSpacing(10);
  main_layout->addLayout(grid_layout);
  this->color_line_edit_ = new ColorLineEdit();
  grid_layout->addWidget(this->color_line_edit_, 0, 0);
  this->r_line_edit_ = new ColorChannelLineEdit();
  grid_layout->addWidget(this->r_line_edit_, 0, 1);
  this->g_line_edit_ = new ColorChannelLineEdit();
  grid_layout->addWidget(this->g_line_edit_, 0, 2);
  this->b_line_edit_ = new ColorChannelLineEdit();
  grid_layout->addWidget(this->b_line_edit_, 0, 3);
  this->a_line_edit_ = new ColorChannelLineEdit();
  grid_layout->addWidget(this->a_line_edit_, 0, 4);

  auto* hex_label = new ColorChannelLabel(tr("Hex"));
  grid_layout->addWidget(hex_label, 1, 0, Qt::AlignHCenter);
  auto* r_label = new ColorChannelLabel(tr("R"));
  grid_layout->addWidget(r_label, 1, 1, Qt::AlignHCenter);
  auto* g_label = new ColorChannelLabel(tr("G"));
  grid_layout->addWidget(g_label, 1, 2, Qt::AlignHCenter);
  auto* b_label = new ColorChannelLabel(tr("B"));
  grid_layout->addWidget(b_label, 1, 3, Qt::AlignHCenter);
  this->a_label_ = new ColorChannelLabel(tr("A"));
  grid_layout->addWidget(this->a_label_, 1, 4, Qt::AlignHCenter);

  main_layout->addWidget(new rusty::SeparatorLine(Qt::Horizontal));

  this->color_palette_list_view_ = new ColorPaletteListView();
  main_layout->addWidget(this->color_palette_list_view_);
}

void ColorChooserWindow::initSignals() {
  connect(this->color_palette_list_view_, &ColorPaletteListView::colorChanged,
          this, &ColorChooserWindow::setColor);
  connect(this->color_picker_, &HSVColorPicker::colorChanged,
          this, &ColorChooserWindow::setColor);
  connect(this->color_line_edit_, &ColorLineEdit::colorChanged,
          this, &ColorChooserWindow::setColor);
  connect(this->r_line_edit_, &ColorChannelLineEdit::valueChanged, [=](int value) {
    this->setColor(QColor(value, this->solid_color_.green(),
                          this->solid_color_.blue(), this->solid_color_.alpha()));
  });
  connect(this->g_line_edit_, &ColorChannelLineEdit::valueChanged, [=](int value) {
    this->setColor(QColor(this->solid_color_.red(), value,
                          this->solid_color_.blue(), this->solid_color_.alpha()));
  });
  connect(this->b_line_edit_, &ColorChannelLineEdit::valueChanged, [=](int value) {
    this->setColor(QColor(this->solid_color_.red(), this->solid_color_.green(),
                          value, this->solid_color_.alpha()));
  });
  connect(this->a_line_edit_, &ColorChannelLineEdit::valueChanged, [=](int value) {
    this->setColor(QColor(this->solid_color_.red(), this->solid_color_.green(),
                          this->solid_color_.blue(), value));
  });
}

void ColorChooserWindow::setSolidColorPalette(const ColorPalette& palette) {
  this->color_palette_list_view_->setColorPalette(palette);
}

void ColorChooserWindow::focusOutEvent(QFocusEvent* event) {
  QWidget::focusOutEvent(event);
  emit this->lostFocus();
}

void ColorChooserWindow::setColor(const QColor& color) {
  if (this->solid_color_ == color) {
    return;
  }
  this->solid_color_ = color;
  this->color_line_edit_->setColor(color);
  this->r_line_edit_->setValue(color.red());
  this->g_line_edit_->setValue(color.green());
  this->b_line_edit_->setValue(color.blue());
  this->a_line_edit_->setValue(color.alpha());
  this->color_picker_->setColor(color);
  this->color_picker_->setPreviewColor(color);
  emit this->colorChanged(color);
}

void ColorChooserWindow::setEnableTransparent(bool enable) {
  this->a_line_edit_->setVisible(enable);
  this->a_label_->setVisible(enable);
}

}  // namespace rusty
