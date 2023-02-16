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
    
    if(!glfwInit())
    {
        std::cout << "GLFW is not initialized!" << std::endl;
    }

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);


    window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);

    if(!window)
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

}

void Window::Loop()
{   
    float r = 1.0f, g = 1.0f, b = 1.0f;
    bool fadeToBlack = false;

    float timeStarted;
    float timeEnded;
    float deltaTime = 0;
    GLuint FPS = 0;
    
    float fpsTimeStarted = glfwGetTime();
    float fpsTimeEnded = 0;

    while (!glfwWindowShouldClose(window))
    {
        timeStarted = glfwGetTime();
        glfwPollEvents();
        ProccessInput();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(r, g, b, 1.0f);
        

        if(fpsTimeEnded - fpsTimeStarted  < 1.0f )
        {
            FPS++;

        } 
        else
        {
            //std::cout << "FPS : " << FPS << std::endl; 
            glfwSetWindowTitle(window, ("fps : " + std::to_string(FPS) + title).c_str());
             FPS = 0;
             fpsTimeStarted = fpsTimeEnded;
        }


        

        //std::cout << deltaTime << std::endl;
        r = (sin(deltaTime) + cos(deltaTime)) * 0.5;
        g = r;

        glfwSwapBuffers(window);
        timeEnded = glfwGetTime();

        deltaTime = timeEnded - timeStarted;
        fpsTimeEnded = glfwGetTime();
        
    }
    

}




void Window::ProccessInput()
{
    if(KeyListener::IsKeyPressed(GLFW_KEY_Q) || KeyListener::IsKeyPressed(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, 1);
    }
}


