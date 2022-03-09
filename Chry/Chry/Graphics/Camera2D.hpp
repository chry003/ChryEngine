#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "Core/Base.hpp"

namespace Chry
{
    class OrthographicCamera
    {
        public:
            OrthographicCamera(float vLeft, float vRight, float vBottom, float vTop);
            ~OrthographicCamera();

            void SetPosition(const glm::vec3& vPosition) { mPosition = vPosition; RecalculateMatrix(); }
            void SetRotation(float vRotation) { mRotation = vRotation; RecalculateMatrix(); }

            float GetRotation() { return mRotation; }
            const glm::vec3& GetPosition() { return mPosition; }

            const glm::mat4& GetViewProjectionMatrix() { return mViewProjectionMatrix; }
            const glm::mat4& GetProjectionMatrix() { return mProjectionMatrix; }
            const glm::mat4& GetViewMatrix() { return mViewMatrix; }

        private:
            void RecalculateMatrix();

        private:
            glm::mat4 mProjectionMatrix;
            glm::mat4 mViewMatrix;
            glm::mat4 mViewProjectionMatrix;

            glm::vec3 mPosition = { 0.0f, 0.0f, 0.0f };
            float mRotation = 0.0f;
    };
}
