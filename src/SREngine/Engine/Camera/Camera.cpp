#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec2 position) :
projectionMatrix(0.0f), viewMatrix(0.0f)
{
    this->position = position;
    adjustProjection();
}

void Camera::adjustProjection()
{
    projectionMatrix = glm::mat4(1.0);
    projectionMatrix = glm::ortho<float>(0.0f, 32.0f * 40, 0.0f, 32.0 * 21.0, 0.0f, 100.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    //glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    
    this->viewMatrix = glm::mat4(1.0);
    this->viewMatrix = glm::lookAt(glm::vec3(position.x, position.y, 20.0f),
                                    cameraFront + glm::vec3(position.x, position.y, 0.0f),
                                    cameraUp);


    return this->viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
    return this->projectionMatrix;
}
