#ifndef UTILS_TIME_H
#define UTILS_TIME_H

#include <GLFW/glfw3.h>
#include <ctime>
#include <unistd.h>

class Time
{
private:


public:
    float timeStarted = glfwGetTime();


    static float GetTime();

};

#endif