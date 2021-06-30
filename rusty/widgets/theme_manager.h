// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_THEME_MANAGER_H_
#define RUSTY_RUSTY_WIDGETS_THEME_MANAGER_H_

#include <functional>
#include <QAction>
#include <QObject>

namespace rusty {

class ThemeManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(ThemeType themeType READ themeType WRITE setThemeType NOTIFY themeTypeChanged)

 public:
  enum ThemeType {
    kLightTheme,
    kDarkTheme,
  };
  Q_ENUM(ThemeType);

  ~ThemeManager() override = default;

  static ThemeManager& instance();

  [[nodiscard]] ThemeType themeType() const;

  void setThemeType(ThemeType theme_type);
  void setThemeType(ThemeType theme_type, bool force_update);

  static bool updateIconPath(QString& icon_path, ThemeType theme_type);

  void registerAction(QAction* action, const QString& icon_name);

  using Callback = std::function<void(bool changed, const QString& icon_name)>;
  void registerWidget(QObject* object, const QString& icon_name, Callback callback);

 signals:
  void themeTypeChanged(ThemeType theme_type);

 private:
  explicit ThemeManager(QObject* parent = nullptr);
  ThemeType theme_type_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_THEME_MANAGER_H_
