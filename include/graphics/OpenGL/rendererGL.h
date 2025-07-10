#pragma once
#include "renderer.h"

class RendererGL : public Renderer {
public:
    void clear(float r, float g, float b, float a) override;
    void draw(
        const VertexArray& va, 
        const IndexBuffer& ib, 
        const Shader& shader
    ) override;
    void setWireframeMode(bool enabled) override;
};