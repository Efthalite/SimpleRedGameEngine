#ifndef ENGINE_ENTITY_MANAGER_H
#define ENGINE_ENTITY_MANAGER_H


#include "Parameters.h"
#include <queue>
#include <array>


class EntityManager
{
private:
    std::queue<Entity> mAvailableEntities{};
    std::array<Signature, MAX_ENTITES> mSignatures{};

    unsigned int mLivingEntitiesCount{};



public:

    EntityManager();

    Entity CreateEntity();
    
    void DestroyEntity(Entity entity);
    void SetSignature(Entity entity, Signature signature);

    // getters

    Signature GetSignature(Entity entity) const;



};


#endif