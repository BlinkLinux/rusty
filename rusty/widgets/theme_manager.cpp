// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/theme_manager.h"

#include <QSharedPointer>

namespace rusty {
namespace {

constexpr const char* kDarkThemeName = "dark";
constexpr const char* kLightThemeName = "light";
constexpr const char* kThemeManagerIcon = "_r_theme_manager_icon_";

}  // namespace

ThemeManager::ThemeManager(QObject* parent) : QObject(parent) {

}

// static
ThemeManager& ThemeManager::instance() {
  static QSharedPointer<ThemeManager> instance{new ThemeManager()};
  static ThemeManager& instance_ref{*instance};
  return instance_ref;
}

bool ThemeManager::updateIconPath(QString& icon_path, ThemeManager::ThemeType theme_type) {
  if (theme_type == ThemeType::kDarkTheme) {
    if (icon_path.contains(kLightThemeName)) {
      icon_path.replace(kLightThemeName, kDarkThemeName);
      return true;
    }
  } else {
    if (icon_path.contains(kDarkThemeName)) {
      icon_path.replace(kDarkThemeName, kLightThemeName);
      return true;
    }
  }
  return false;
}

ThemeManager::ThemeType ThemeManager::themeType() const {
  return this->theme_type_;
}

void ThemeManager::setThemeType(ThemeManager::ThemeType theme_type) {
  if (this->theme_type_ != theme_type) {
    this->theme_type_ = theme_type;
    emit this->themeTypeChanged(theme_type);
  }
}

void ThemeManager::setThemeType(ThemeManager::ThemeType theme_type, bool force_update) {
  if (force_update || this->theme_type_ != theme_type) {
    this->theme_type_ = theme_type;
    emit this->themeTypeChanged(theme_type);
  }
}

void ThemeManager::registerAction(QAction* action, const QString& icon_name) {
  Q_ASSERT(action != nullptr);
  action->setProperty(kThemeManagerIcon, icon_name);
  auto conn = connect(this, &ThemeManager::themeTypeChanged, [=](ThemeManager::ThemeType theme_type) {
    QString last_icon_name = action->property(kThemeManagerIcon).toString();
    const bool changed = ThemeManager::updateIconPath(last_icon_name, theme_type);
    if (changed) {
      action->setProperty(kThemeManagerIcon, last_icon_name);
      action->setIcon(QIcon(last_icon_name));
    }
  });
  connect(action, &QAction::destroyed, [this, conn]() {
    this->disconnect(conn);
  });
}

void ThemeManager::registerWidget(QObject* object, const QString& icon_name, ThemeManager::Callback callback) {
  Q_ASSERT(object != nullptr);
  object->setProperty(kThemeManagerIcon, icon_name);
  auto conn = connect(this, &ThemeManager::themeTypeChanged, [=](ThemeManager::ThemeType theme_type) {
    QString last_icon_name = object->property(kThemeManagerIcon).toString();
    const bool changed = ThemeManager::updateIconPath(last_icon_name, theme_type);
    if (changed) {
      object->setProperty(kThemeManagerIcon, last_icon_name);
    }
    callback(changed, last_icon_name);
  });
  connect(object, &QAction::destroyed, [this, conn]() {
    this->disconnect(conn);
  });
}

}  // namespace rusty
