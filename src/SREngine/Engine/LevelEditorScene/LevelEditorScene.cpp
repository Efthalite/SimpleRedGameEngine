#include "LevelEditorScene.h"
#include <iostream>
#include <glad/glad.h>

#include "../KeyListener/KeyListener.h"
#include "../Window/Window.h"

LevelEditorScene::LevelEditorScene()
{
    std::cout << "Inside Level editor scene\n";   
    std::cout << "initialization\n";
}

LevelEditorScene::~LevelEditorScene()
{


    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &vboID);
    glDeleteBuffers(1, &eboID);
    glDeleteVertexArrays(1, &vaoID);

}



void LevelEditorScene::Update(float dt) 
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUseProgram(shaderProgram);
    float uTime = glfwGetTime();

    glUniform1f(glGetUniformLocation(shaderProgram, "u_Time"), uTime);

    glBindVertexArray(vaoID);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glBindVertexArray(0);
    glUseProgram(0);

}

void LevelEditorScene::Init()
{
    
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &vertexShaderSource, 0);
    glCompileShader(vertexID);

    int success;
    char errorLog[2048];

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

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexID);
    glAttachShader(shaderProgram, fragmentID);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        std::cout << "Failed to link shaders\n";

        glGetProgramInfoLog(shaderProgram, sizeof(errorLog)/sizeof(errorLog[0]), NULL, errorLog);
        std::cout << errorLog << "\n";   
    }

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);



    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glGenBuffers(1, &eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementArray), elementArray, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}


