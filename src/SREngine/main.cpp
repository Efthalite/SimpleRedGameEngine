#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include "Window/Window.h"

Window Window::w_Instance;


int main()
{
    Window& window = Window::Get();
    window.Run();

    std::cout << "test";

    return 0;
}