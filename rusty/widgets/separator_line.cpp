// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/separator_line.h"

namespace rusty {
namespace {

constexpr int kFixedSize = 12;

}  // namespace

SeparatorLine::SeparatorLine(Qt::Orientation orientation, QWidget* parent)
    : QFrame(parent),
      orientation_(orientation) {
  this->setOrientation(orientation);
}

void SeparatorLine::setOrientation(Qt::Orientation orientation) {
  this->orientation_ = orientation;
  if (orientation_ == Qt::Horizontal) {
    this->setFixedHeight(kFixedSize);
    this->setFrameShape(QFrame::Shape::HLine);
  } else {
    this->setFixedWidth(kFixedSize);
    this->setFrameShape(QFrame::Shape::VLine);
  }
  this->update();
}

}  // namespace rusty
