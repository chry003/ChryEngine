#include "pch.hpp"
#include "Camera2D.hpp"

namespace Chry
{
    OrthographicCamera::OrthographicCamera(float vLeft, float vRight, float vBottom, float vTop)
        : mProjectionMatrix(glm::ortho(vLeft, vRight, vBottom, vTop, -1.0f, 1.0f)), mViewMatrix(1.0f)
    {
        mViewProjectionMatrix = mProjectionMatrix * mViewMatrix;
    }

    OrthographicCamera::~OrthographicCamera()
    {
        
    }

    void OrthographicCamera::RecalculateMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), mPosition) * glm::rotate(glm::mat4(1.0f), glm::radians(mRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        mViewMatrix = glm::inverse(transform);
        mViewProjectionMatrix = mProjectionMatrix * mViewMatrix;
    }
}
