#ifndef ENGINE_ECS_H
#define ENGINE_ECS_H

#include <bitset>

// alias 
using Entity = unsigned int;
using ComponentType = unsigned int;




// Set parameters

constexpr Entity MAX_ENTITES = 5000; 
constexpr ComponentType MAX_COMPONENTS = 32;


// alias

using Signature = std::bitset<MAX_COMPONENTS>;


#endif