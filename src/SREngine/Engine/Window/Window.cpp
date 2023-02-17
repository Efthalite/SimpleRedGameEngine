#include "Window.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include <string>

#include <ctime>
#include <unistd.h>

#include "../MouseListener/MouseListener.h"
#include "../KeyListener/KeyListener.h"
#include "../../Utils/Time.h"

#include "../Scene/Scene.h"
#include "../LevelEditorScene/LevelEditorScene.h"
#include "../LevelScene/LevelScene.h"


Time mTime;

Window Window::w_Instance;
MouseListener MouseListener::ml_Instance;
KeyListener KeyListener::kl_Instance;

void Window::Run()
{
    std::cout << "GLFW " << glfwGetVersionString() << std::endl;

    Init();
    Loop();


    // Free the memory
    glfwDestroyWindow(window);
    glfwTerminate();
    glfwSetErrorCallback(NULL);

}

void Window::Init()
{
    
    if(GL_TRUE != glfwInit())
    {
        std::cout << "GLFW is not initialized!" << std::endl;
    }

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);

    if(!this->window)
    {
        std::cout << "Failed to create a window" << std::endl;
    }


    // Setting callbacks
    glfwSetCursorPosCallback(window, MouseListener::MousePosCallback);
    glfwSetMouseButtonCallback(window, MouseListener::MouseButtonCallback);
    glfwSetScrollCallback(window, MouseListener::MousePosCallback);
    glfwSetKeyCallback(window, KeyListener::KeyCallBack);


    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwShowWindow(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glViewport(0, 0, this->width, this->height);

    ChangeScene(0);

}

void Window::Loop()
{   
   
    bool fadeToBlack = false;

    float timeStarted;
    float timeEnded;
    float deltaTime = 0;
    float FPS = 0;


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ProccessInput();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(r, g, b, 1.0f);


        currentScene->Init();
        currentScene->Update(deltaTime);
        
       
       

        
        glfwSetWindowTitle(this->window, ("FPS: " + std::to_string(FPS) + "\t" + this->title).c_str()); 

        glfwSwapBuffers(window);
        timeEnded = glfwGetTime();

        deltaTime = timeEnded - timeStarted;
        timeStarted = timeEnded;
        
        FPS = 1 / deltaTime;
    }
    

}




void Window::ProccessInput()
{
    if(KeyListener::IsKeyPressed(GLFW_KEY_Q) || KeyListener::IsKeyPressed(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, 1);
    }
}

void Window::ChangeScene(int newScene)
{
    
    switch(newScene)
    {
        case 0:
            currentScene = new LevelEditorScene();
            break;
        case 1:
            currentScene = new LevelScene();
            break;
        default:
            std::cout << "Unknown scene \"" << newScene << "\"";
            break;
    }
}


