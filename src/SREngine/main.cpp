#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include "Window/Window.h"
#include "MouseListener/MouseListener.h"

Window Window::w_Instance;
MouseListener MouseListener::ml_Instance;


int main()
{
    Window& window = Window::Get();
    window.Run();
    MouseListener& mListener = MouseListener::Get();

    
    std::cout << "test";

    return 0;
}