// Copyright (c) 2023 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_OPENGL_FPS_COUNTER_H_
#define RUSTY_RUSTY_OPENGL_FPS_COUNTER_H_

#include <QElapsedTimer>
#include <QObject>

namespace rusty {

class FpsCounter : public QObject {
  Q_OBJECT
 public:
  explicit FpsCounter(QObject* parent = nullptr);

  void init();

  void update();

  void setActive(bool active);

  qint64 totalFrames() const { return total_frames_; }

  void resetTotalFrames() { total_frames_ = 0; }

  double fps() const { return this->fps_; }

 signals:
  void fpsChanged(double fps);

 private:
  QElapsedTimer timer_{};
  int frames_{0};
  bool active_{false};
  qint64 total_frames_{0};
  double fps_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_OPENGL_FPS_COUNTER_H_
