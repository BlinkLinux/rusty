// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/models/software_license_model.h"

#include <QBrush>
#include <QDebug>

namespace rusty {
namespace {

constexpr const char* kName = "name";
constexpr const char* kVersion = "version";
constexpr const char* kUrl = "url";
constexpr const char* kLicense = "license";
constexpr const char* kLicenseUrl = "licenseUrl";

}  // namespace

SoftwareLicenseModel::SoftwareLicenseModel(QObject *parent) : QAbstractTableModel(parent) {

}

void SoftwareLicenseModel::setLicenseFile(const QString& file) {
  this->beginResetModel();
  this->list_ = parseAppLicense(file);
  this->endResetModel();
}

int SoftwareLicenseModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return this->list_.length();
}

int SoftwareLicenseModel::columnCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return 2;
}

QVariant SoftwareLicenseModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) {
    return {};
  }

  const auto& software = this->list_.at(index.row());
  switch(role) {
    case kNameRole: {
      return software.name;
    }
    case kVersionRole: {
      return software.version;
    }
    case kUrlRole: {
      return software.url;
    }
    case kLicenseRole: {
      return software.license;
    }
    case kLicenseUrlRole: {
      return software.license_url;
    }
    default: {
      return {};
    }
  }
}

QHash<int, QByteArray> SoftwareLicenseModel::roleNames() const {
  return {
      {kNameRole, kName},
      {kVersionRole, kVersion},
      {kUrlRole, kUrl},
      {kLicenseRole, kLicense},
      {kLicenseUrlRole, kLicenseUrl},
  };
}

QVariant SoftwareLicenseModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (orientation != Qt::Horizontal || section > kLicenseColumn) {
    return {};
  }

  switch (role) {
    case Qt::DisplayRole: {
      if (section == kSoftwareColumn ) {
        return tr("Software");
      }
      return tr("License");
    }
    default: {
      return {};
    }
  }
}

}  // namespace rusty