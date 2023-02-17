#ifndef ENGINE_LEVEL_EDITOR_SCENE_H
#define ENGINE_LEVEL_EDITOR_SCENE_H

#include "../Scene/Scene.h"

class LevelEditorScene : public Scene
{
private:
    bool changingScene = false;
    float timeToChangeScene = 2.0f;


public:
    LevelEditorScene();

    void Update(float dt) override;


};


#endif