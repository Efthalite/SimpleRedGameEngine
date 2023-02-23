#ifndef RENDERER_TEXTURE_H
#define RENDERER_TEXTURE_H

#include <string>   


class Texture
{
private:
    std::string filePath;
    unsigned int textureID;

public:

    Texture(std::string filePath);

    void Bind();
    void Unbind();


};



#endif