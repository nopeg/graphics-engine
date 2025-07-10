#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath) 
{
    string vShaderString = readShader(vertexPath);
    const char* vShaderCode = vShaderString.c_str();

    string fShaderString = readShader(fragmentPath);
    const char* fShaderCode = fShaderString.c_str();


    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);
    checkCompileErrors(id, "PROGRAM");


    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() 
{
    glDeleteProgram(id);
}

string Shader::readShader(const char* shaderPath)
{
    string shaderString;
    ifstream shaderFile;
    shaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try 
    {
        shaderFile.open(shaderPath);
        stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderString = shaderStream.str();
    } 
    catch (ifstream::failure& e) 
    {
        throw runtime_error("COULD NOT READ SHADER FILE");
    }
    return shaderString;
}

void Shader::use() const 
{
    glUseProgram(id);
}

void Shader::checkCompileErrors(unsigned int shader, const string& type) 
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") 
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) 
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            throw runtime_error(
                "Shader compilation error of type: " 
                + type 
                + "\n" 
                + infoLog
            );
        }
    } 
    else 
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) 
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            throw runtime_error(
                "Linking error of type: " 
                + type 
                + "\n" 
                + infoLog
            );
        }
    }
}