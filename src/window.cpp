#include "window.h"

Window::Window(int width, int height, const char* title) 
{
    if (!glfwInit()) 
    {
        throw runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        throw runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) 
    {
        glfwTerminate();
        throw runtime_error("Failed to initialize GLEW");
    }

    cout << "OpenGL Version: " << glGetString(GL_VERSION) << endl;
}

Window::~Window() 
{
    glfwTerminate();
}

bool Window::shouldClose() const 
{
    return glfwWindowShouldClose(window);
}

void Window::swapBuffers() const 
{
    glfwSwapBuffers(window);
}

void Window::pollEvents() const 
{
    glfwPollEvents();
}

void Window::clear() const 
{
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::isKeyPressed(int key) const 
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}