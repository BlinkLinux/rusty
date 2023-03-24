// Copyright (c) 2023 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU General Public License
// that can be found in the LICENSE file.

#ifndef RUSTY_RUSTY_OPENGL_VERTEX_BUFFER_LAYOUT_H_
#define RUSTY_RUSTY_OPENGL_VERTEX_BUFFER_LAYOUT_H_

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLVertexArrayObject>
#include <QVector>

namespace rusty {

struct VertexBufferElement {
  unsigned int type{};
  unsigned int count{};
  unsigned int normalized{};

  static unsigned int sizeOfType(unsigned int type);

  [[nodiscard]] unsigned int size() const { return this->count * sizeOfType(this->type); }
};

using VertexBufferElements = QVector<VertexBufferElement>;

class VertexBufferLayout {
 public:
  VertexBufferLayout();

  void push(unsigned int type, unsigned int count);

  [[nodiscard]] const VertexBufferElements& elements() const { return this->elements_; }

  [[nodiscard]] unsigned int stride() const { return this->stride_; }

 private:
  VertexBufferElements elements_{};
  unsigned int stride_{};
};

void addBuffer(QOpenGLVertexArrayObject& vao, QOpenGLBuffer& vbo,
               const VertexBufferLayout& layout, QOpenGLFunctions_4_5_Core* gl_functions);

void addBuffer(QOpenGLVertexArrayObject& vao, QOpenGLBuffer& vbo,
               const VertexBufferLayout& layout, QOpenGLFunctions* gl_functions);

}  // namespace rusty

#endif  // RUSTY_RUSTY_OPENGL_VERTEX_BUFFER_LAYOUT_H_
