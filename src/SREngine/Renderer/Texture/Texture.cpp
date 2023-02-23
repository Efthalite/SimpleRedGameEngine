#include "Texture.h"

#include <iostream>

#include <glad/glad.h>
#include <stb_image.h>


Texture::Texture(std::string filePath) 
{
    this->filePath = filePath;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    // Repeat image in both directions
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // When strecthing pixelate

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    const char* fileName = filePath.c_str();
    stbi_set_flip_vertically_on_load(1);

    int widthBuffer, heightBuffer, channelsBuffer;
    unsigned char* image = stbi_load(fileName, &widthBuffer, &heightBuffer, &channelsBuffer, 0);

    if(image != nullptr)
    {
        if(channelsBuffer == 3)
        {
             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthBuffer, heightBuffer, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
             std::cout << "Current channels amount is - " << channelsBuffer << "\n";
        }
        else if(channelsBuffer == 4)
        {
             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthBuffer, heightBuffer, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
             std::cout << "Current channels amount is - " << channelsBuffer << "\n";
        }
        else{
            std::cout << "More than 4 channels or less than 3 channels!\nCurrent channels amount is - " << channelsBuffer << "\n";
        }
    }
    else{
        std::cout << "Error couldn't open '" << filePath << "'" << std::endl;
    }

    stbi_image_free(image);

}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

