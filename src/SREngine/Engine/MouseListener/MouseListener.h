#ifndef ENGINE_MOUSE_LISTENER_H
#define ENGINE_MOUSE_LISTENER_H


#include <GLFW/glfw3.h>

class MouseListener 
{
private:
    // Variables

    double scrollX, scrollY;
    double xPos, yPos, lastX, lastY;
    bool mouseButtonPressed[3];
    bool isDragging;

    GLuint buttonAmount;

protected:

    
    MouseListener();


public:

    static MouseListener& Get()
    {
        static MouseListener ml_Instance;

        return ml_Instance;
    }


    // Functions

    static void MousePosCallback(GLFWwindow* window, double xpos, double ypos);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    static void EndFrame();

    // Getters
    
    static float GetX();
    static float GetY();
    static float GetDx();
    static float GetDy();
    static float GetScrollX();
    static float GetScrollY();
    static bool IsDragging();
    static bool MouseButtonDown(int button);



};




#endif