#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <string>

class GLFWwindow;


class Window
{
private:
    int width, height;
    std::string title;
    GLFWwindow* window;

    static Window w_Instance;

    Window() 
    {
        this->width = 1920;
        this->height = 1080;
        this->title = "SR";
    }

public:
    Window(const Window&) = delete;
    static Window& Get()
    {
        return w_Instance;
    }


    void Run();
    void Init();
    void Loop();
    void ProccessInput();

};



#endif