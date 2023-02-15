#ifndef ENGINE_KEY_LISTENER_H
#define ENGINE_KEY_LISTENER_H

#include <GLFW/glfw3.h>


class KeyListener
{
private:
    static KeyListener ml_Instance;

    KeyListener()
    {}

public:
    KeyListener(const KeyListener&) = delete;


};


#endif