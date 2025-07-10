#pragma once

class IndexBuffer {
public:
    virtual ~IndexBuffer() = default;
    
    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    virtual unsigned int getCount() const = 0;
    
    static IndexBuffer* create(const unsigned int* data, unsigned int count);
};