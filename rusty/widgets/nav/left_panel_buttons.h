// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_NAV_LEFT_PANEL_BUTTONS_FRAME_H_
#define RUSTY_RUSTY_WIDGETS_NAV_LEFT_PANEL_BUTTONS_FRAME_H_

#include <QAbstractButton>
#include <QButtonGroup>
#include <QFrame>
#include <QVBoxLayout>

namespace rusty {

class LeftPanelButtons : public QFrame {
  Q_OBJECT

 public:
  explicit LeftPanelButtons(QWidget* parent = nullptr);
  ~LeftPanelButtons() override = default;

  QAbstractButton* addButton(int button_id, const QString& icon, const QString& text);

  QAbstractButton* button(int button_id);

  void addStretch();

  [[nodiscard]] int activeId() const;

 public slots:
  void setActiveId(int button_id);

 signals:
  void activeChanged(int button_id);

 private:
  void initUi();
  void initSignals();

  QButtonGroup* button_group_{nullptr};
  QVBoxLayout* button_layout_{nullptr};
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_NAV_LEFT_PANEL_BUTTONS_FRAME_H_
