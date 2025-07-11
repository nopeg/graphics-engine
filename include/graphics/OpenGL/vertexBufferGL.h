#pragma once

#include <GL/glew.h>
#include "config.h"
#include "vertexBuffer.h"

class VertexBufferGL : public VertexBuffer
{
public:
    VertexBufferGL(const void* data, unsigned int size);
    ~VertexBufferGL();

    void bind() const override;
    void unbind() const override;
    void setData(const void* data, unsigned int size) override;

private:
    unsigned int rendererID;
};