// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_FORM_SECTION_TITLE_H_
#define RUSTY_RUSTY_WIDGETS_FORM_SECTION_TITLE_H_

#include <QLabel>

namespace rusty {

class FormSectionTitle : public QLabel {
  Q_OBJECT
 public:
  explicit FormSectionTitle(const QString& text, QWidget* parent = nullptr);
  ~FormSectionTitle() override = default;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_FORM_SECTION_TITLE_H_
