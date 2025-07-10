#include "shader.h"
#include "shaderGL.h"

Shader* Shader::create(const char* vertexPath, const char* fragmentPath) {
    return new ShaderGL(vertexPath, fragmentPath);
}