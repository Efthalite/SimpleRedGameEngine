#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <string>

class GLFWwindow;
class Scene;

class Window
{
private:
    int width, height;
    std::string title;
    GLFWwindow* window;

    Scene* currentScene;


protected:


    Window();

    
public:
    static Window& Get()
    {
        static  Window w_Instance;
        return w_Instance;
    }
    float r = 1.0f, g = 1.0f, b = 1.0f;

    void Run();
    void Init();
    void Loop();
    void ProccessInput();

    void ChangeScene(int newScene);



};



#endif