#pragma once

class VertexBuffer {
public:
    virtual ~VertexBuffer() = default;
    
    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    virtual void setData(const void* data, unsigned int size) = 0;
    
    static VertexBuffer* create(const void* data, unsigned int size);
};