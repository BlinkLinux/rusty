// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_SRC_BASE_FILE_H_
#define RUSTY_SRC_BASE_FILE_H_

#include <QString>

namespace rusty {

QByteArray readBinaryFile(const QString& path);

QString readTextFile(const QString& path);

bool readTextFile(const QString& path, QString& content);

bool writeBinaryFile(const QString& path, const QByteArray& bytes);

}  // namespace rusty

#endif  // RUSTY_SRC_BASE_FILE_H_
