#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include <string>
#include <glm/glm.hpp>


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


    // uniform shares


    void SetUniform1f(const char* uniformName, float value) const;
    void SetUniformMatrix4f(const char* uniformName, glm::mat4 value);
    void SetUniformTexture(const char* uniformName, int slot);

    


};


#endif