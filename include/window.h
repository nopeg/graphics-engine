#pragma once

#include "config.h"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose() const;
    void swapBuffers() const;
    void pollEvents() const;
    void clear() const;
    bool isKeyPressed(int key) const;

    GLFWwindow* get() const { return window; }

private:
    GLFWwindow* window;
};