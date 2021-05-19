// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include <gtest/gtest.h>

#include "rusty/gui/image.h"

namespace rusty {

TEST(GuiImageTest, TestColorizeImage) {
  QImage orig_image(":/tests/gui/color-buttons.png");
  ASSERT_FALSE(orig_image.isNull());

  const QImage play_pause_image = orig_image.copy(24, 0, 36, 36);
  ASSERT_FALSE(play_pause_image.isNull());
  ASSERT_TRUE(play_pause_image.save("play-pause.png"));

  const QImage red_image = colorizeImage(play_pause_image, Qt::red);
  ASSERT_FALSE(red_image.isNull());
  ASSERT_TRUE(red_image.save("red-play-pause.png"));
}

TEST(GuiImageTest, TestColorizeImage2) {
  QImage orig_image(":/tests/gui/alien-icon.png");
  ASSERT_FALSE(orig_image.isNull());

  const QImage green_image = colorizeImage(orig_image, QColor("#adbcc3"), Qt::green);
  ASSERT_FALSE(green_image.isNull());
  ASSERT_TRUE(green_image.save("green-alien-icon.png"));
}

}  // namespace rusty