#ifndef ENGINE_KEY_LISTENER_H
#define ENGINE_KEY_LISTENER_H

#include <GLFW/glfw3.h>


class KeyListener
{
private:
    static KeyListener kl_Instance;

    KeyListener();

    bool keyPressed[350];

    GLuint buttonAmount;

public:
    KeyListener(const KeyListener&) = delete;

    static KeyListener& Get()
    {
        return kl_Instance;
    }

    static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
    static bool IsKeyPressed(int keyCode);

};


#endif