#include "Time.h"

float Time::GetTime()
{
    return (float)(glfwGetTime() - timeStarted);
}