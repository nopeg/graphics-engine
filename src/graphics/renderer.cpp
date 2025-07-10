#include "renderer.h"
#include "rendererGL.h"

Renderer* Renderer::create() {
    return new RendererGL();
}