#include "LevelEditorScene.h"
#include <iostream>
#include <glad/glad.h>

#include "../KeyListener/KeyListener.h"
#include "../Window/Window.h"



LevelEditorScene::LevelEditorScene() :
defaultShader("shaders/defaultVertex.glsl", "shaders/defaultFragment.glsl"),
defaultTexture("assets/images/myFace.jpg")
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

void LevelEditorScene::MovingCamera(float dt)
{
    float movementSpeed = 750.0f;

    if(KeyListener::IsKeyPressed(GLFW_KEY_D))
    {
        camera.position.x += dt * movementSpeed;
    }
    if(KeyListener::IsKeyPressed(GLFW_KEY_A))
    {
        camera.position.x -= dt * movementSpeed;
    }

    

}



void LevelEditorScene::Update(float dt) 
{
    float uTime = glfwGetTime();

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    //camera.position.x -= dt * 130.0;

    MovingCamera(dt);

    //std::cout << "call\n";
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    defaultShader.Use();


    defaultShader.SetUniformTexture("TEX_SAMPLER", 0);
    glActiveTexture(GL_TEXTURE0);
    defaultTexture.Bind();
  

    defaultShader.SetUniform1f("u_Time", uTime);
    defaultShader.SetUniformMatrix4f("u_Projection", camera.getProjectionMatrix());
    defaultShader.SetUniformMatrix4f("u_View", camera.getViewMatrix());



    glBindVertexArray(vaoID);


    

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


    defaultShader.Detach();

    glBindVertexArray(0);
        glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    



}

void LevelEditorScene::Init() 
{
   


    this->camera = Camera(glm::vec2(0.0));
    camera.position.y -= 300.0f;


    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);

    
    glGenBuffers(1, &eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementArray), elementArray, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    


}


