#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include <string>


class Shader
{
private:
    unsigned int shaderProgramID;


public:
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
    
    std::string LoadFromFile(std::string filePath);

    void Use();
    void Detach();
    void Compile();
    unsigned int getID()
    {
        return shaderProgramID;
    }


};


#endif