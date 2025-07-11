#pragma once

#include <GL/glew.h>
#include "config.h"
#include "renderer.h"

class RendererGL : public Renderer {
public:
    //RendererGL(Window* window);
    void clear(float r, float g, float b, float a) override;
    void draw(
        const VertexArray& va, 
        const IndexBuffer& ib, 
        const Shader& shader
    ) override;
    void setWireframeMode(bool enabled) override;
};