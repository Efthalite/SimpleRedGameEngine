#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H


class Scene
{
private:


public:
    Scene() = default;

    virtual void Update(float dt) = 0;

};


#endif