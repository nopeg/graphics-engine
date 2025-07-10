#include "vertexArray.h"

VertexArray::VertexArray() 
{
    glGenVertexArrays(1, &rendererID);
}

VertexArray::~VertexArray() 
{
    glDeleteVertexArrays(1, &rendererID);
}

void VertexArray::bind() const 
{
    glBindVertexArray(rendererID);
}

void VertexArray::unbind() const 
{
    glBindVertexArray(0);
}

void VertexArray::addBuffer(
    const VertexBuffer& vb, 
    unsigned int layout, 
    unsigned int count, 
    GLenum type, 
    bool normalized, 
    unsigned int stride, 
    const void* pointer) 
{
    bind();
    vb.bind();
    glVertexAttribPointer(layout, count, type, normalized, stride, pointer);
    glEnableVertexAttribArray(layout);
}