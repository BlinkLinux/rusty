// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_SRC_BASE_PROCESS_H_
#define RUSTY_SRC_BASE_PROCESS_H_

#include <QStringList>

namespace rusty {

bool getCommandOutput(const QString& cmd, QString& output);
bool getCommandOutput(const QString& cmd, const QStringList& args, QString& output);

}  // namespace rusty

#endif  // RUSTY_SRC_BASE_PROCESS_H_
