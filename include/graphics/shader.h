#pragma once

#include "config.h"

class Shader 
{
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;
    unsigned int getID() const { return id; }

private:
    unsigned int id;
    string readShader(const char* shaderPath);
    void checkCompileErrors(unsigned int shader, const string& type);
};