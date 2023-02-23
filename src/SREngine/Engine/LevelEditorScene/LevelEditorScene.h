#ifndef ENGINE_LEVEL_EDITOR_SCENE_H
#define ENGINE_LEVEL_EDITOR_SCENE_H

#include "../Scene/Scene.h"
#include "../Camera/Camera.h"

#include "../../Renderer/Shader/Shader.h"
#include "../../Renderer/Texture/Texture.h"


class LevelEditorScene : public Scene
{
private:

    Shader defaultShader;
    Texture defaultTexture;

    unsigned int vaoID, vboID, eboID;

    float vertexArray[4*9] = 
    {
        // Position                 // Color                    // UV Coordinates
         0.5f, -0.5f,  0.0f,        1.0f, 0.0f, 0.0f, 1.0f,     1, 0,
        -0.5f,  0.5f,  0.0f,        0.0f, 1.0f, 0.0f, 1.0f,     0, 1,
         0.5f,  0.5f,  0.0f,        0.0f, 0.0f, 1.0f, 1.0f,     1, 1,
        -0.5f, -0.5f,  0.0f,        1.0f, 1.0f, 0.0f, 1.0f,     0, 0

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
    void MovingCamera(float dt);


};


#endif