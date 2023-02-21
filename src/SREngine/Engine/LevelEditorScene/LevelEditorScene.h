#ifndef ENGINE_LEVEL_EDITOR_SCENE_H
#define ENGINE_LEVEL_EDITOR_SCENE_H

#include "../Scene/Scene.h"
#include "../../Renderer/Shader/Shader.h"

class LevelEditorScene : public Scene
{
private:

    Shader defaultShader;

    unsigned int vaoID, vboID, eboID;

    float vertexArray[4*7] = 
    {
        // Position                 // Color
         0.5f, -0.5f,  0.0f,        1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.0f,        0.0f, 1.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.0f,        0.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f,  0.0f,        1.0f, 1.0f, 0.0f, 1.0f

    };

    unsigned int elementArray[6] =
    {
        0, 1, 2,
        0, 1, 3
    };


public:
    LevelEditorScene();
    ~LevelEditorScene();

    void Update(float dt) override;
    void Init() override;


};


#endif