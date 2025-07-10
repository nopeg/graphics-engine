#pragma once

#include "config.h"
#include "vertexBuffer.h"

class VertexArray 
{
public:
    VertexArray();
    ~VertexArray();

    void bind() const;
    void unbind() const;
    void addBuffer(const VertexBuffer& vb, unsigned int layout, unsigned int count, 
                  GLenum type, bool normalized, unsigned int stride, const void* pointer);

private:
    unsigned int rendererID;
};