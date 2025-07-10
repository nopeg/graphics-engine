#include "vertexArrayGL.h"

VertexArrayGL::VertexArrayGL() 
{
    glGenVertexArrays(1, &rendererID);
}

VertexArrayGL::~VertexArrayGL() 
{
    glDeleteVertexArrays(1, &rendererID);
}

void VertexArrayGL::bind() const 
{
    glBindVertexArray(rendererID);
}

void VertexArrayGL::unbind() const
{
    glBindVertexArray(0);
}

void VertexArrayGL::addBuffer(
    const VertexBuffer& vb, 
    unsigned int layout, 
    unsigned int count, 
    ShaderDataType type, 
    bool normalized, 
    unsigned int stride, 
    const void* pointer
) 
{
    bind();
    vb.bind();
    GLenum glType = type == ShaderDataType::Float ? GL_FLOAT : GL_UNSIGNED_INT;
    glVertexAttribPointer(layout, count, glType, normalized ? GL_TRUE : GL_FALSE, stride, pointer);
    glEnableVertexAttribArray(layout);
}