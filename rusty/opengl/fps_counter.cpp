// Copyright (c) 2023 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/opengl/fps_counter.h"

namespace rusty {

FpsCounter::FpsCounter(QObject* parent) : QObject(parent) {

}

void FpsCounter::init() {
  this->active_ = true;
  this->timer_.start();
}

void FpsCounter::setActive(bool active) {
  this->active_ = active;
}

void FpsCounter::update() {
  if (!this->active_) {
    return;
  }
  this->total_frames_ += 1;

  const qint64 elapsed = this->timer_.elapsed();
  if (elapsed > 0) {
    this->fps_ = this->frames_ / (static_cast<double>(elapsed) / 1000.0);
    emit this->fpsChanged(this->fps_);
  }
  if ((this->frames_ % 100) == 0) {
    this->timer_.start();
    this->frames_ = 0;
  }
  this->frames_ += 1;
}

}  // namespace rusty