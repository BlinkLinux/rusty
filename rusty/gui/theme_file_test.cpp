// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include <gtest/gtest.h>
#include <QDebug>

#include "rusty/gui/theme_file.h"

namespace rusty {

TEST(GuiThemeTest, TestReadTheme) {
  const QString content = readThemeFile(":/tests/gui/night-theme.css");
  ASSERT_FALSE(content.isEmpty());
  qDebug() << qPrintable(content);
}

}  // namespace rusty