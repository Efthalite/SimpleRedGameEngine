#include "LevelScene.h"
#include <iostream>

#include "../KeyListener/KeyListener.h"
#include "../Window/Window.h"


void LevelScene::Update(float dt)
{
    
}

void LevelScene::Init()
{
    
}

LevelScene::LevelScene()
{
    std::cout << "Inside level scene\n";
    Window::Get().r = 1.0f;
    Window::Get().g = 1.0f;
    Window::Get().b = 1.0f;
}
