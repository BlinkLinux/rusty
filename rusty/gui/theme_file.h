// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_GUI_THEME_FILE_H_
#define RUSTY_RUSTY_GUI_THEME_FILE_H_

#include <QString>

namespace rusty {

/**
 * Read theme file and parse CSS_IMPORT macro and import dependents.
 */
QString readThemeFile(const QString& file);

}  // namespace rusty

#endif  // RUSTY_RUSTY_GUI_THEME_FILE_H_
