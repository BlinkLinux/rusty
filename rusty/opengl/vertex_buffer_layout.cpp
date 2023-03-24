// Copyright (c) 2023 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/opengl/vertex_buffer_layout.h"

namespace rusty {


unsigned int VertexBufferElement::sizeOfType(unsigned int type) {
  switch (type) {
    case GL_BYTE: return sizeof(char);
    case GL_UNSIGNED_BYTE: return sizeof(unsigned char);
    case GL_SHORT: return sizeof(short);
    case GL_UNSIGNED_SHORT: return sizeof(unsigned short);
    case GL_INT: return sizeof(int);
    case GL_UNSIGNED_INT: return sizeof(unsigned int);
    case GL_FLOAT: return sizeof(float);
    case GL_2_BYTES: return sizeof(char) * 2;
    case GL_3_BYTES: return sizeof(char) * 3;
    case GL_4_BYTES: return sizeof(char) * 4;
    case GL_DOUBLE: return sizeof(double);
    default: {
      // unreachable
      return 0;
    }
  }
}

VertexBufferLayout::VertexBufferLayout() {

}

void VertexBufferLayout::push(unsigned int type, unsigned int count) {
  this->elements_.push_back({type, count, GL_FALSE});
  this->stride_ += count * VertexBufferElement::sizeOfType(type);
}

void addBuffer(QOpenGLVertexArrayObject& vao, QOpenGLBuffer& vbo,
               const VertexBufferLayout& layout, QOpenGLFunctions_4_5_Core* gl_functions) {
  vao.bind();
  vbo.bind();

  size_t offset = 0;
  const auto& elements = layout.elements();
  for (int i = 0; i < elements.size(); ++i) {
    const auto& element = elements.at(i);
    gl_functions->glEnableVertexAttribArray(i);
    gl_functions->glVertexAttribPointer(i, static_cast<int>(element.count),
                                        element.type, element.normalized,
                                        static_cast<int>(layout.stride()),
                                        (const void*) offset);
    offset += element.size();
  }
  vbo.release();
  vao.release();
}

void addBuffer(QOpenGLVertexArrayObject& vao, QOpenGLBuffer& vbo,
               const VertexBufferLayout& layout, QOpenGLFunctions* gl_functions) {
  vao.bind();
  vbo.bind();

  size_t offset = 0;
  const auto& elements = layout.elements();
  for (int i = 0; i < elements.size(); ++i) {
    const auto& element = elements.at(i);
    gl_functions->glEnableVertexAttribArray(i);
    gl_functions->glVertexAttribPointer(i, static_cast<int>(element.count),
                                        element.type, element.normalized,
                                        static_cast<int>(layout.stride()),
                                        (const void*) offset);
    offset += element.size();
  }
}

}  // namespace rusty