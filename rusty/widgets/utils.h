// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_WIDGETS_UTILS_H_
#define RUSTY_RUSTY_WIDGETS_UTILS_H_

#include <QLayout>
#include <QObject>
#include <QWidget>

namespace rusty {

QObject* getAncestor(QObject* object);

QWidget* getAncestorWidget(QWidget* widget);

void clearLayout(QLayout* widget);

QPointF mapToGlobal(QWidget* widget, const QPointF& point);

QPointF mapToParent(QWidget* widget, const QPointF& point);

QPointF mapFromGlobal(QWidget* widget, const QPointF& point);

QPointF mapFromParent(QWidget* widget, const QPointF& point);

}  // namespace rusty

#endif  // RUSTY_RUSTY_WIDGETS_UTILS_H_
