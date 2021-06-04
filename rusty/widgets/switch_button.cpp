// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/switch_button.h"

namespace rusty {
namespace {

constexpr const char* kDefaultBrush =  "#009688";
constexpr const char* kDefaultThumb = "#d5d5d5";
constexpr const qreal kCheckedOpacity = 0.5;
constexpr const qreal kUncheckedOpacity = 0.38;

constexpr const int kAnimationDuration = 120;
constexpr const int kDefaultHeight = 25;
constexpr const qreal kBorderRadius = kDefaultHeight * 0.5;
constexpr const int kDefaultWidth = kDefaultHeight * 2;
constexpr const int kOffsetEnd = kDefaultHeight;

}  // namespace

SwitchButton::SwitchButton(QWidget* parent)
    : QAbstractButton(parent),
      offset_(0),
      thumb_(kDefaultThumb),
      brush_(Qt::black),
      opacity_(kUncheckedOpacity),
      animation_(new QPropertyAnimation(this, "offset", this)) {
  this->setCheckable(true);
  this->setFixedSize(kDefaultWidth, kDefaultHeight);
  this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void SwitchButton::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event);

  QPainter p(this);
  p.setPen(Qt::NoPen);
  if (isEnabled()) {
    p.setBrush(this->brush_);
    p.setOpacity(this->opacity_);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.drawRoundedRect(this->rect(), kBorderRadius, kBorderRadius);
    p.setBrush(this->thumb_);
    p.setOpacity(1.0);
    p.drawEllipse(QRectF(this->offset_, 0.0, kDefaultHeight, kDefaultHeight));
  } else {
    p.setBrush(Qt::black);
    p.setOpacity(0.12);
    p.drawRoundedRect(this->rect(), kBorderRadius, kBorderRadius);
    p.setOpacity(1.0);
    p.setBrush(QColor("#BDBDBD"));
    p.drawEllipse(QRectF(this->offset_, 0.0, kDefaultHeight, kDefaultHeight));
  }
}

void SwitchButton::mouseReleaseEvent(QMouseEvent* event) {
  QAbstractButton::mouseReleaseEvent(event);
  if (event->button() & Qt::LeftButton) {
    this->resetAnimation(this->isChecked());
  }
}

void SwitchButton::enterEvent(QEvent* event) {
  this->setCursor(Qt::PointingHandCursor);
  QAbstractButton::enterEvent(event);
}

void SwitchButton::checkStateSet() {
  QAbstractButton::checkStateSet();
  this->resetAnimation(this->isChecked());
}

void SwitchButton::resetAnimation(bool is_checked) {
  if (is_checked) {
    this->brush_.setColor(kDefaultBrush);
    this->thumb_.setColor(this->brush_.color());
    this->opacity_ = kCheckedOpacity;

    this->animation_->setStartValue(kOffsetEnd);
    this->animation_->setEndValue(0);
    this->animation_->setDuration(kAnimationDuration);
    this->animation_->start();
  } else {
    this->brush_.setColor(Qt::black);
    this->thumb_.setColor(kDefaultThumb);
    this->opacity_ = kUncheckedOpacity;

    this->animation_->setStartValue(this->offset_);
    this->animation_->setEndValue(kOffsetEnd);
    this->animation_->setDuration(kAnimationDuration);
    this->animation_->start();
  }
}

void SwitchButton::resizeEvent(QResizeEvent* event) {
  QWidget::resizeEvent(event);
  if (this->isChecked()) {
    this->setOffset(kOffsetEnd);
  } else {
    this->setOffset(0);
  }
}

}  // namespace rusty