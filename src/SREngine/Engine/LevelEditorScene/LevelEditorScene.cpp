#include "LevelEditorScene.h"
#include <iostream>
#include <glad/glad.h>

#include "../KeyListener/KeyListener.h"
#include "../Window/Window.h"



LevelEditorScene::LevelEditorScene() :
defaultShader("shaders/defaultVertex.glsl", "shaders/defaultFragment.glsl")
{
    std::cout << "Inside Level editor scene\n";   
    std::cout << "initialization\n";
}

LevelEditorScene::~LevelEditorScene()
{


    glDeleteProgram(defaultShader.getID());
    glDeleteBuffers(1, &vboID);
    glDeleteBuffers(1, &eboID);
    glDeleteVertexArrays(1, &vaoID);

}



void LevelEditorScene::Update(float dt) 
{
    //std::cout << "call\n";
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    defaultShader.Use();
    float uTime = glfwGetTime();
    glBindVertexArray(vaoID);

    glUniform1f(glGetUniformLocation(defaultShader.getID(), "u_Time"), uTime);

    

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


    defaultShader.Detach();

    glBindVertexArray(0);
        glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    



}

void LevelEditorScene::Init() 
{

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


