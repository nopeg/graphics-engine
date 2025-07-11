#include "config.h"
#include "window.h"
#include "shader.h"
#include "renderer.h"
#include "vertexBuffer.h"
#include "vertexArray.h"
#include "indexBuffer.h"

int main() 
{
    try 
    {
        Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
        Renderer* renderer = Renderer::create();
        Shader* shader = Shader::create(
            "./resources/shaders/vertex.glsl", 
            "./resources/shaders/fragment.glsl"
        );

        float vertices[] = 
        {
             0.5f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };

        unsigned int indices[] = 
        {
            0, 1, 3,
            1, 2, 3
        };

        VertexArray* va = VertexArray::create();
        VertexBuffer* vb = VertexBuffer::create(vertices, sizeof(vertices));
        IndexBuffer* ib = IndexBuffer::create(indices, 6);

        va->addBuffer(*vb, 0, 3, ShaderDataType::Float, false, 3 * sizeof(float), 0);

        while (!window.shouldClose()) 
        {
            renderer->clear(0.2f, 0.3f, 0.3f, 1.0f);

            shader->use();
            va->bind();
            ib->bind();

            renderer->setWireframeMode(true);
            renderer->draw(*va, *ib, *shader);

            window.swapBuffers();
            window.pollEvents();
        }

        delete va;
        delete vb;
        delete ib;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << endl;
        return -1;
    }

    return 0;
}