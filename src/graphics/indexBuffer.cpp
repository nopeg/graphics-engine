#include "indexBuffer.h"
#include "indexBufferGL.h"

IndexBuffer* IndexBuffer::create(const unsigned int* data, unsigned int count) 
{
    return new IndexBufferGL(data, count);
}