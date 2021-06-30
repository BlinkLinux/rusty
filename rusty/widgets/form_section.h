// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_FORM_SECTION_H_
#define RUSTY_RUSTY_WIDGETS_FORM_SECTION_H_

#include <QFrame>

namespace rusty {

class FormSection : public QFrame {
  Q_OBJECT

 public:
  explicit FormSection(QWidget* parent = nullptr);
  ~FormSection() override = default;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_FORM_SECTION_H_
