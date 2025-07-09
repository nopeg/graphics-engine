#include "vertexArray.h"
#include "vertexBuffer.h"  // Добавляем этот include

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::bind() const {
    glBindVertexArray(m_RendererID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}

void VertexArray::addBuffer(const VertexBuffer& vb, unsigned int layout, unsigned int count, 
                          GLenum type, bool normalized, unsigned int stride, const void* pointer) {
    bind();
    vb.bind();
    glVertexAttribPointer(layout, count, type, normalized, stride, pointer);
    glEnableVertexAttribArray(layout);
}