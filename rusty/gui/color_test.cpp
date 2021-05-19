// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include <gtest/gtest.h>

#include "rusty/gui/color.h"

namespace rusty {

TEST(GuiColorTest, TestParseColor) {
  ASSERT_EQ(parseColor("rgba (255, 128, 12, 2)"), QColor(255, 128, 12));
  ASSERT_EQ(parseColor("rgba (400, 128, 12, 2)"), QColor(255, 128, 12));
  ASSERT_EQ(parseColor(" rgba (255, 128, 12, 0.5)"), QColor(255, 128, 12, 127));
  ASSERT_EQ(parseColor("#fff"), QColor(255, 255, 255));
  ASSERT_EQ(parseColor("#ff0011"), QColor(255, 0, 17));
  ASSERT_EQ(parseColor("slateblue"), QColor(106, 90, 205));

  ASSERT_EQ(parseColor("hsla(900, 15%, 90%, 0.5)"), QColor(226, 233, 233, 127));
  ASSERT_EQ(parseColor("hsl(900, 15%, 90%)"), QColor(226, 233, 233));
  ASSERT_EQ(parseColor("hsl(900, 0.15, 90%)"), QColor(226, 233, 233));
  ASSERT_EQ(parseColor("hsl(9999999999999999999, 0, 0)"), QColor(0, 0, 0));
  ASSERT_EQ(parseColor("hsl(45, 100%, 50%)"), QColor(255, 191, 0));
  ASSERT_EQ(parseColor("hsl(-315, 100%, 50%)"), QColor(255, 191, 0));
  ASSERT_EQ(parseColor("hsl(-675, 100%, 50%)"), QColor(255, 191, 0));

  ASSERT_FALSE(parseColor("hsla(900, 15%, 90%)").isValid());
}

}  // namespace rusty