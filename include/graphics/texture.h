#pragma once

#include <string>

enum class TextureWrapMode
{
    Repeat,
    MirroredRepeat,
    ClampToEdge,
    ClampToBorder
};

enum class TextureFilterMode
{
    Linear,
    Nearest
};

class Texture
{
public:
    virtual ~Texture() = default;

    virtual void bind(unsigned int slot = 0) const = 0;
    virtual void unbind() const = 0;

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual void setWrapMode(TextureWrapMode mode) = 0;
    virtual void setFilterMode(TextureFilterMode mode) = 0;

    static Texture* create(const std::string& path);
};