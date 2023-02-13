#include "Window.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void Window::Run()
{
    std::cout << "GLFW " << glfwGetVersionString() << std::endl;

    Init();
    Loop();

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
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


        glfwSwapBuffers(window);
    }
    

}

