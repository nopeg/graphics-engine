#include "indexBufferGL.h"

IndexBufferGL::IndexBufferGL(const unsigned int* data, unsigned int count) 
    : count(count) 
{
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data ? data : nullptr, GL_STATIC_DRAW);
}

IndexBufferGL::~IndexBufferGL()
{
    glDeleteBuffers(1, &rendererID);
}

void IndexBufferGL::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
}

void IndexBufferGL::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}