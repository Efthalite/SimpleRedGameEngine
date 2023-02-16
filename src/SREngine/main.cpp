#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include "Engine/Window/Window.h"
#include "Engine/MouseListener/MouseListener.h"
#include "Engine/KeyListener/KeyListener.h"



int main()
{
    Window& window = Window::Get();
    window.Run();
    MouseListener& mListener = MouseListener::Get();


    
    std::cout << "test";

    return 0;
}