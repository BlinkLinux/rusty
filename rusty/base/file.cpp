// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/base/file.h"

#include <QDebug>
#include <QFile>
#include <QStandardPaths>

namespace rusty {

QByteArray readBinaryFile(const QString& path) {
  QFile file(path);
  if (file.exists()) {
    if (!file.open(QIODevice::ReadOnly)) {
      qWarning() << "failed to open file:" << path;
      return {};
    }
    QByteArray bytes = file.readAll();
    file.close();
    return bytes;
  }
  qWarning() << "file not found:" << path;
  return {};
}

QString readTextFile(const QString& path) {
  QFile file(path);
  if (file.exists()) {
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      qWarning() << "failed to open file:" << path;
      return "";
    }
    QString content = file.readAll();
    file.close();
    return content;
  }
  qWarning() << "file not found:" << path;
  return "";
}

bool readTextFile(const QString& path, QString& content) {
  QFile file(path);
  if (file.exists()) {
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      qWarning() << "failed to open file:" << path;
      return false;
    }
    content = file.readAll();
    file.close();
    return true;
  }
  qWarning() << "file not found:" << path;
  return false;
}

bool writeBinaryFile(const QString& path, const QByteArray& bytes) {
  QFile file(path);
  if (!file.open(QIODevice::WriteOnly)) {
    qWarning() << "failed to open file:" << path;
    return false;
  }
  file.write(bytes);
  file.close();
  return true;
}

QDir getCacheDir() {
  QDir dir = QStandardPaths::standardLocations(QStandardPaths::CacheLocation).first();
  if (!dir.exists()) {
    dir.mkpath(".");
  }
  return dir;
}

QDir concatDir(const QDir& parent_dir, const QString& folder_name) {
  if (!parent_dir.exists(folder_name)) {
    parent_dir.mkpath(folder_name);
  }
  return QDir(parent_dir.filePath(folder_name));
}

bool createDirs(const QString& dir) {
  return QDir(dir).mkpath(".");
}

bool createParentDirs(const QString& filepath) {
  return QFileInfo(filepath).absoluteDir().mkpath(".");
}

}  // namespace rusty