#include "vertexBuffer.h"
#include "vertexBufferGL.h"

VertexBuffer* VertexBuffer::create(const void* data, unsigned int size) 
{
    return new VertexBufferGL(data, size);
}