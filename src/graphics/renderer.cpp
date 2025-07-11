#include "rendererGL.h"

Renderer* Renderer::create() {
    return new RendererGL();
}