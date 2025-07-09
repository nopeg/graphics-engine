#pragma once

#include "config.h"

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;
    unsigned int getID() const { return m_ID; }

private:
    unsigned int m_ID;

    void checkCompileErrors(unsigned int shader, const std::string& type);
};