#include "rendererGL.h"
#include <GL/glew.h>

void RendererGL::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RendererGL::draw(
    const VertexArray& va, 
    const IndexBuffer& ib, 
    const Shader& shader
) 
{
    shader.use();
    va.bind();
    ib.bind();
    glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
}

void RendererGL::setWireframeMode(bool enabled) {
    glPolygonMode(GL_FRONT_AND_BACK, enabled ? GL_LINE : GL_FILL);
}