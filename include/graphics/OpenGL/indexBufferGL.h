#pragma once

#include <GL/glew.h>
#include "config.h"
#include "indexBuffer.h"

class IndexBufferGL : public IndexBuffer
{
public:
    IndexBufferGL(const unsigned int* data, unsigned int count);
    ~IndexBufferGL();
    
    void bind() const override;
    void unbind() const override ;
    unsigned int getCount() const override  { return count; }

private:
    unsigned int rendererID;
    unsigned int count;
};