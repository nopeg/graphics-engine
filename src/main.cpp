#include "config.h"
#include "cmath"
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

        float vertices[] = {
            // positions          // colors
            0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // top right - red
            0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom right - green
            -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   // bottom left - blue
            -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f    // top left - yellow
        };

        unsigned int indices[] = 
        {
            0, 1, 3,
            1, 2, 3
        };

        VertexArray* va = VertexArray::create();
        VertexBuffer* vb = VertexBuffer::create(vertices, sizeof(vertices));

        va->addBuffer(*vb, 0, 3, ShaderDataType::Float, false, 6 * sizeof(float), (void*)0);
        va->addBuffer(*vb, 1, 3, ShaderDataType::Float, false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        IndexBuffer* ib = IndexBuffer::create(indices, 6);

        while (!window.shouldClose()) 
        {
            renderer->clear(0.2f, 0.3f, 0.3f, 1.0f);

            float timeValue = glfwGetTime();
            float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
            
            shader->use();
            shader->setUniform("time", static_cast<float>(glfwGetTime()));
            
            va->bind();
            ib->bind();

            renderer->draw(*va, *ib, *shader);

            window.swapBuffers();
            window.pollEvents();
        }

        delete va;
        delete vb;
        delete ib;
        delete shader;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << endl;
        return -1;
    }

    return 0;
}