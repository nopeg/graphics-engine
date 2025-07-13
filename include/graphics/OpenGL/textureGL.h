#pragma once

#include <GL/glew.h>
#include "texture.h"

class TextureGL : public Texture
{
public:
    TextureGL(const std::string& path);
    ~TextureGL();

    void bind(unsigned int slot = 0) const override;
    void unbind() const override;

    int getWidth() const override;
    int getHeight() const override;

    void setWrapMode(TextureWrapMode mode) override;
    void setFilterMode(TextureFilterMode mode) override;

private:
    unsigned int mId;
    int mWidth;
    int mHeight;
    int mChannels;

    void loadFromFile(const std::string& path);
};