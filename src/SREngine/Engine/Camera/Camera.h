#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include <glm/glm.hpp>


class Camera
{
private:
    glm::mat4 projectionMatrix, viewMatrix;



public:
    Camera(glm::vec2 position);
    
    glm::vec2 position;

    void adjustProjection();

    // getters

    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();


};



#endif