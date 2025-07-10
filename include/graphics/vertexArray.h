#pragma once
#include "vertexBuffer.h"

enum class ShaderDataType {
    Float,
    UInt
};

class VertexArray 
{
public:
    virtual ~VertexArray() = default;
    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    virtual void addBuffer(
        const VertexBuffer& vb, 
        unsigned int layout, 
        unsigned int count, 
        ShaderDataType type, 
        bool normalized, 
        unsigned int stride, 
        const void* pointer
    ) = 0;
    
    static VertexArray* create();
};