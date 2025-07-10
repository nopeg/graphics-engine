#include "vertexBufferGL.h"

VertexBufferGL::VertexBufferGL(const void* data, unsigned int size) 
{
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBufferGL::~VertexBufferGL() 
{
    glDeleteBuffers(1, &rendererID);
}

void VertexBufferGL::bind() const 
{
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
}

void VertexBufferGL::unbind() const 
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferGL::setData(const void* data, unsigned int size) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}