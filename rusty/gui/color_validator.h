// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef RUSTY_RUSTY_GUI_COLOR_VALIDATOR_H
#define RUSTY_RUSTY_GUI_COLOR_VALIDATOR_H

#include <QValidator>

namespace rusty {

class ColorValidator : public QValidator {
  Q_OBJECT

 public:
  explicit ColorValidator(QObject* parent = nullptr);
  ~ColorValidator() override = default;

  State validate(QString& input, int& pos) const override;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_GUI_COLOR_VALIDATOR_H
