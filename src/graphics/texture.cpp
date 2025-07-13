#include "texture.h"
#include "textureGL.h"

Texture* Texture::create(const std::string& path)
{
    return new TextureGL(path);
}