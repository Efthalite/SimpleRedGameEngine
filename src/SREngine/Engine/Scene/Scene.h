#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

#include "../Camera/Camera.h"

class Scene
{
private:


protected: 
    

public:
    Scene() = default;
    Camera camera = Camera(glm::vec2(0.0));
    virtual void Update(float dt) = 0;
    virtual void Init() = 0;

};


#endif