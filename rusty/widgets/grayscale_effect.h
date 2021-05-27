// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_WIDGETS_GRAYSCALE_EFFECT_H_
#define RUSTY_RUSTY_WIDGETS_WIDGETS_GRAYSCALE_EFFECT_H_

#include <QGraphicsEffect>

namespace rusty {

class GrayscaleEffect : public QGraphicsEffect {
  Q_OBJECT
 public:
  explicit GrayscaleEffect(QObject* parent = nullptr);
  ~GrayscaleEffect() override = default;

 protected:
  void draw(QPainter* painter) override;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_WIDGETS_GRAYSCALE_EFFECT_H_
