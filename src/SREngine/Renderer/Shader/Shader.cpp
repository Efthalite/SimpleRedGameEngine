#include "Shader.h"
#include <glad/glad.h>

#include <iostream>
#include <sstream>
#include <fstream>

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    int success;
    char errorLog[2048];

    unsigned int vertexID, fragmentID;

    std::string vsBuffer = LoadFromFile(vertexShaderPath);
    std::string fsBuffer = LoadFromFile(fragmentShaderPath);

    const char* vertexShaderSource = vsBuffer.c_str();
    const char* fragmentShaderSource = fsBuffer.c_str();


    vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &vertexShaderSource, 0);
    glCompileShader(vertexID);

    

    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        std::cout << "Failed to compile Vertex Shader\n";

        glGetShaderInfoLog(vertexID, sizeof(errorLog)/sizeof(errorLog[0]), NULL, errorLog);
        std::cout << errorLog << "\n";   
    }


    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentShaderSource, 0);
    glCompileShader(fragmentID);

    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        std::cout << "Failed to compile Fragment Shader\n";

        glGetShaderInfoLog(fragmentID, sizeof(errorLog)/sizeof(errorLog[0]), NULL, errorLog);
        std::cout << errorLog << "\n";   
    }

    shaderProgramID = glCreateProgram();

    glAttachShader(shaderProgramID, vertexID);
    glAttachShader(shaderProgramID, fragmentID);
    glLinkProgram(shaderProgramID);

    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if(!success)
    {
        std::cout << "Failed to link shaders\n";

        glGetProgramInfoLog(shaderProgramID, sizeof(errorLog)/sizeof(errorLog[0]), NULL, errorLog);
        std::cout << errorLog << "\n";   
    }

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
}

std::string Shader::LoadFromFile(std::string filePath)
{
    std::ifstream inFile(filePath.c_str(), std::ios::binary);
    std::stringstream bufferStream;
    std::string bufferString;


    if(!inFile)
    {
        std::cout << "Couldn't find " << filePath << "\n";
        return nullptr;
    }


    bufferStream << inFile.rdbuf();
    bufferString = bufferStream.str();


    return bufferString;
}

void Shader::Use()
{
    glUseProgram(shaderProgramID);
}

void Shader::Detach()
{
    glUseProgram(0);
}

void Shader::Compile()
{
}

void Shader::SetUniform1f(const char *uniformName, float value) const
{
    glUniform1f(glGetUniformLocation(shaderProgramID, uniformName), value);
}

void Shader::SetUniformMatrix4f(const char *uniformName, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, uniformName), 1, GL_FALSE, &value[0][0]);
}

void Shader::SetUniformTexture(const char *uniformName, int slot)
{
    glUniform1i(glGetUniformLocation(shaderProgramID, uniformName), slot);
}
