#include "textureGL.h"
#include <iostream>
#include <stb_image.h>

TextureGL::TextureGL(const std::string& path)
    : mId(0), mWidth(0), mHeight(0), mChannels(0)
{
    loadFromFile(path);
    setWrapMode(TextureWrapMode::Repeat);
    setFilterMode(TextureFilterMode::Linear);
}

TextureGL::~TextureGL()
{
    glDeleteTextures(1, &mId);
}

void TextureGL::loadFromFile(const std::string& path)
{
    stbi_set_flip_vertically_on_load(true);
    
    unsigned char* data = stbi_load(
        path.c_str(), 
        &mWidth, 
        &mHeight, 
        &mChannels, 
        0
    );

    if (!data)
    {
        std::cerr << "Failed to load texture: " << path << std::endl;
        return;
    }

    GLenum format = GL_RGB;
    if (mChannels == 1)
        format = GL_RED;
    else if (mChannels == 3)
        format = GL_RGB;
    else if (mChannels == 4)
        format = GL_RGBA;

    glGenTextures(1, &mId);
    glBindTexture(GL_TEXTURE_2D, mId);

    glTexImage2D(
        GL_TEXTURE_2D, 
        0, 
        format, 
        mWidth, 
        mHeight, 
        0, 
        format, 
        GL_UNSIGNED_BYTE, 
        data
    );

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

void TextureGL::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, mId);
}

void TextureGL::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

int TextureGL::getWidth() const
{
    return mWidth;
}

int TextureGL::getHeight() const
{
    return mHeight;
}

void TextureGL::setWrapMode(TextureWrapMode mode)
{
    glBindTexture(GL_TEXTURE_2D, mId);

    GLenum wrapMode = GL_REPEAT;
    switch (mode)
    {
        case TextureWrapMode::Repeat:
            wrapMode = GL_REPEAT;
            break;
        case TextureWrapMode::MirroredRepeat:
            wrapMode = GL_MIRRORED_REPEAT;
            break;
        case TextureWrapMode::ClampToEdge:
            wrapMode = GL_CLAMP_TO_EDGE;
            break;
        case TextureWrapMode::ClampToBorder:
            wrapMode = GL_CLAMP_TO_BORDER;
            float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
            break;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
}

void TextureGL::setFilterMode(TextureFilterMode mode)
{
    glBindTexture(GL_TEXTURE_2D, mId);

    switch (mode)
    {
        case TextureFilterMode::Linear:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            break;
            
        case TextureFilterMode::Nearest:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            break;
    }
}