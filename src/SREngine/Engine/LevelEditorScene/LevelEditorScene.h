#ifndef ENGINE_LEVEL_EDITOR_SCENE_H
#define ENGINE_LEVEL_EDITOR_SCENE_H

#include "../Scene/Scene.h"

class LevelEditorScene : public Scene
{
private:

    const char* vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec4 aColor;\n"
    "out vec4 fColor;"
        "    uniform float u_Time;"
    "void main()"
    "{"
    "    fColor = aColor;"
    "    float x = (sin(u_Time) + cos(u_Time)) * 0.5;"
    "    gl_Position = vec4(aPos.x + x, aPos.yz, 1.0f);"
    "}";

    const char* fragmentShaderSource = 
    "#version 330 core\n"
    "in vec4 fColor;"
    "out vec4 color;"
    "void main()"
    "{"
    "color = fColor;"
    "}";

    unsigned int vertexID, fragmentID, shaderProgram;
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