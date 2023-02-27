#ifndef ENGINE_GAME_OBJECT_H
#define ENGINE_GAME_OBJECT_H


#include <string>
#include <list>

#include "../Component/Component.h"



class GameObject
{
private:
    std::string name;


public:
    GameObject(std::string name);


};

#endif