#include "EntityManager.h"

EntityManager::EntityManager()
{
    for (Entity entity = 0; entity < MAX_ENTITES; ++entity)
    {
        mAvailableEntities.push(entity);
    }
    
}

Entity EntityManager::CreateEntity()
{
    
    Entity id = mAvailableEntities.front();
    mAvailableEntities.pop();
    ++mLivingEntitiesCount;

    return id;
}

void EntityManager::DestroyEntity(Entity entity)
{
    mSignatures[entity].reset();
    mAvailableEntities.push(entity);
    --mLivingEntitiesCount;
}

void EntityManager::SetSignature(Entity entity, Signature signature)
{
    mSignatures[entity] = signature;
}

Signature EntityManager::GetSignature(Entity entity) const
{
    return mSignatures[entity];
}
