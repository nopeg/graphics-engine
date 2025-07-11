#include "rendererGL.h"

/*RendererGL::RendererGL(Window* window) {
    glfwMakeContextCurrent(window->get());
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("Failed to initialize GLEW");
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    glEnable(GL_DEPTH_TEST);
}*/

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