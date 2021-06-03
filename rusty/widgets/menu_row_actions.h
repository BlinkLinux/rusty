// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_MENU_ROW_ACTIONS_H_
#define RUSTY_RUSTY_WIDGETS_MENU_ROW_ACTIONS_H_

#include <QMap>
#include <QPushButton>
#include <QWidget>
#include <QWidgetAction>

namespace rusty {

class MenuRowActions : public QWidgetAction {
  Q_OBJECT
 public:
  explicit MenuRowActions(QObject* parent = nullptr);
  ~MenuRowActions() override = default;

  QPushButton* addButton(const QString& icon_path, int button_id);

  QPushButton* button(int button_id);

 signals:
  void buttonClicked(int button_id);

 protected:
  QWidget* createWidget(QWidget* parent) override;

  void deleteWidget(QWidget* widget) override;

 private:
  QWidget* button_container_{nullptr};
  QMap<int, QPushButton*> buttons_{};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_MENU_ROW_ACTIONS_H_
