#include "MouseListener.h"

// Constructor

MouseListener::MouseListener() :
scrollX(0.0), scrollY(0.0),
xPos(0.0), yPos(0.0),
lastX(0.0), lastY(0.0),
buttonAmount(sizeof(Get().mouseButtonPressed) / sizeof(Get().mouseButtonPressed[0]))
{

}

// Functions

void MouseListener::MousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
    Get().lastX = Get().xPos;
    Get().lastY = Get().yPos;

    Get().xPos = xpos;
    Get().yPos = ypos;

    Get().isDragging = Get().mouseButtonPressed[0] || Get().mouseButtonPressed[1] ||Get().mouseButtonPressed[2] ;


}


void MouseListener::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{

    if(action == GLFW_PRESS && Get().buttonAmount > button )
    {
        Get().mouseButtonPressed[button] = true;
    } else if(action == GLFW_RELEASE  && Get().buttonAmount > button)
    {
        Get().mouseButtonPressed[button] = false;
        Get().isDragging = false;
    }


}

void MouseListener::MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    Get().scrollX = xoffset;
    Get().scrollY = yoffset;
}


void MouseListener::EndFrame()
{
    Get().scrollX = 0.0;
    Get().scrollY = 0.0;
    Get().lastX = Get().xPos;
    Get().lastY = Get().yPos;
}

// Getters


float MouseListener::GetX()
{
    return (float)Get().xPos;
}

float MouseListener::GetY()
{
    return (float)Get().yPos;
}

float MouseListener::GetDx()
{
    return (float)(Get().xPos - Get().xPos);
}

float MouseListener::GetDy()
{
    return (float)(Get().yPos - Get().yPos);
}

float MouseListener::GetScrollX()
{
    return (float)Get().scrollX;
}

float MouseListener::GetScrollY()
{
    return (float)Get().scrollY;
}

bool MouseListener::IsDragging()
{
    return Get().isDragging;
}

bool MouseListener::MouseButtonDown(int button)
{
    return Get().buttonAmount > button ? Get().mouseButtonPressed[button] : false;
}


