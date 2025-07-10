#pragma once
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

class Renderer {
public:
    virtual ~Renderer() = default;
    
    virtual void clear(float r, float g, float b, float a) = 0;
    virtual void draw(
        const VertexArray& va, 
        const IndexBuffer& ib, 
        const Shader& shader
    ) = 0;
    virtual void setWireframeMode(bool enabled) = 0;
    
    static Renderer* create();
};