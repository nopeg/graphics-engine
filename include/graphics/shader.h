#pragma once
#include <string>

class Shader {
public:
    virtual ~Shader() = default;
    
    virtual void use() const = 0;
    virtual void setUniform(const std::string& name, int value) = 0;
    virtual void setUniform(const std::string& name, float value) = 0;
    
    static Shader* create(const char* vertexPath, const char* fragmentPath);
};