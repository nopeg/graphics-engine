#include "vertexArray.h"
#include "vertexArrayGL.h"

VertexArray* VertexArray::create()
{
    return new VertexArrayGL();
}