#include "config.h"
#include "window.h"
#include "shader.h"
#include "vertexBuffer.h"
#include "vertexArray.h"
#include "indexBuffer.h"

int main() 
{
    try 
    {
        Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
        Shader shader(
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

        VertexArray va;

        VertexBuffer vb(vertices, sizeof(vertices));

        va.addBuffer(vb, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        IndexBuffer ib(indices, 6);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        while (!window.shouldClose()) 
        {
            if (window.isKeyPressed(GLFW_KEY_ESCAPE))
                glfwSetWindowShouldClose(window.get(), true);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            window.clear();

            shader.use();
            va.bind();
            glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);

            window.swapBuffers();
            window.pollEvents();
        }
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << endl;
        return -1;
    }

    return 0;
}