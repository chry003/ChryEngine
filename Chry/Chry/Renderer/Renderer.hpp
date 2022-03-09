#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Buffer.hpp"
#include "Graphics/Shader.hpp"
#include "Graphics/Camera2D.hpp"

namespace Chry
{

    class Renderer
    {
        public:
            inline static void SetClearColor(const glm::vec4& vColor) { glClearColor(vColor.r, vColor.g, vColor.b, vColor.a); }
            inline static void Draw(const Ref<VertexArray>& vVertexArray) { glDrawElements(GL_TRIANGLES, vVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr); }

            static void Begin(OrthographicCamera& vCamera);
            static void Submit(const Ref<VertexArray>& vVertexArray, const Ref<Shader>& vShader, const glm::mat4& vTransform = glm::mat4(1.0f));
            static void End();

        private:
            struct SceneData
            {
                glm::mat4 OrthographicCameraViewProjectionMatrix;
            };

            static SceneData* mRendererElements;
    };

}
