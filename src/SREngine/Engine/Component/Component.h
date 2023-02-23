#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H



class Component
{
private:



public:
    Component() = default;

    virtual void Update(float dt) = 0;
    



};


#endif