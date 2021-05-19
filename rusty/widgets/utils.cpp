// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/widgets/utils.h"

#include <QPainter>
#include <QPainterPath>

namespace rusty {

QObject* getAncestor(QObject* object) {
  Q_ASSERT(object != nullptr);
  QObject* parent = object;
  while (parent != nullptr && parent->parent() != nullptr) {
    parent = parent->parent();
  }
  return parent;
}

QWidget* getAncestorWidget(QWidget* widget) {
  Q_ASSERT(widget != nullptr);
  QWidget* parent = widget;
  while (parent != nullptr && parent->parentWidget() != nullptr) {
    parent = parent->parentWidget();
  }
  return parent;
}

void clearLayout(QLayout* layout) {
  QLayoutItem* child = layout->takeAt(0);
  while (child != nullptr) {
    delete child->widget();
    delete child;
    child = layout->takeAt(0);
  }
}

QPointF mapToGlobal(QWidget* widget, const QPointF& point) {
  const QPoint top_left = widget->geometry().topLeft();
  const QPoint mapped_top_left = widget->mapToGlobal(top_left);
  return {
      point.x() + (mapped_top_left.x() - top_left.x()),
      point.y() + (mapped_top_left.y() - top_left.y()),
  };
}

QPointF mapToParent(QWidget* widget, const QPointF& point) {
  const QPoint top_left = widget->geometry().topLeft();
  const QPoint mapped_top_left = widget->mapToParent(top_left);
  return {
      point.x() + (mapped_top_left.x() - top_left.x()),
      point.y() + (mapped_top_left.y() - top_left.y()),
  };
}

QPointF mapFromGlobal(QWidget* widget, const QPointF& point) {
  const QPoint top_left = widget->geometry().topLeft();
  const QPoint mapped_top_left = widget->mapFromGlobal(top_left);
  return {
      point.x() + (mapped_top_left.x() - top_left.x()),
      point.y() + (mapped_top_left.y() - top_left.y()),
  };
}

QPointF mapFromParent(QWidget* widget, const QPointF& point) {
  const QPoint top_left = widget->geometry().topLeft();
  const QPoint mapped_top_left = widget->mapFromParent(top_left);
  return {
      point.x() + (mapped_top_left.x() - top_left.x()),
      point.y() + (mapped_top_left.y() - top_left.y()),
  };
}

}  // namespace rusty