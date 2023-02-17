#include "LevelEditorScene.h"
#include <iostream>

#include "../KeyListener/KeyListener.h"
#include "../Window/Window.h"

LevelEditorScene::LevelEditorScene()
{
    std::cout << "Inside Level editor scene\n";   
}



void LevelEditorScene::Update(float dt) 
{
    if(!changingScene && KeyListener::IsKeyPressed(GLFW_KEY_SPACE))
    {
        changingScene = true;
    }
    if(changingScene && timeToChangeScene > 0.0)
    {
        timeToChangeScene -= dt;
        Window::Get().r -= dt * 5.0f;
        Window::Get().g -= dt * 5.0f;
        Window::Get().b -= dt * 5.0f;
    }
    else if(changingScene)
    {
        Window::Get().ChangeScene(1);
    }

}


