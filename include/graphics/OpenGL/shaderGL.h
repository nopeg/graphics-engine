#pragma once

#include <GL/glew.h>
#include "config.h"
#include "shader.h"

class ShaderGL : public Shader
{
public:
    ShaderGL(const char* vertexPath, const char* fragmentPath);
    ~ShaderGL();

    void use() const override;
    void setUniform(const std::string& name, int value) override;
    void setUniform(const std::string& name, float value) override;
    
    unsigned int getID() const { return id; }

private:
    unsigned int id;
    string readShader(const char* shaderPath);
    void checkCompileErrors(unsigned int shader, const string& type);
};