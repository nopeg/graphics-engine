#pragma once

#include "config.h"
#include "vertexBufferGL.h"
#include "vertexArray.h"

class VertexArrayGL : public VertexArray
{
public:
    VertexArrayGL();
    ~VertexArrayGL();

    void bind() const override;
    void unbind() const override;
    void addBuffer(
        const VertexBuffer& vb, 
        unsigned int layout, 
        unsigned int count, 
        ShaderDataType type, 
        bool normalized, 
        unsigned int stride, 
        const void* pointer
    ) override;

private:
    unsigned int rendererID;
};