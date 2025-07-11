#pragma once

#include "config.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose() const;
    void close();
    void swapBuffers() const;
    void pollEvents() const;
    bool isKeyPressed(int key) const;

    GLFWwindow* get() const { return window; }

private:
    GLFWwindow* window;
};