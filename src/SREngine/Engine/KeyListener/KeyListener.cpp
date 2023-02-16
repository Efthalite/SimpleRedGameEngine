#include "KeyListener.h"

KeyListener::KeyListener() :
buttonAmount(sizeof(keyPressed)/sizeof(keyPressed[0]))
{

}


void KeyListener::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        Get().keyPressed[key] = true;
    } else if(action == GLFW_RELEASE)
    {
        Get().keyPressed[key] = false;
    }
}


bool KeyListener::IsKeyPressed(int keyCode)
{
    return keyCode < Get().buttonAmount ? Get().keyPressed[keyCode] : false;
}



