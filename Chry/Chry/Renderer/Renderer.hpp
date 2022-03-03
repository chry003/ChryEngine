#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Buffer.hpp"
#include "Graphics/Shader.hpp"

namespace Chry
{

    class Renderer
    {
        public:
            inline static void SetClearColor(const glm::vec4& vColor) { glClearColor(vColor.r, vColor.g, vColor.b, vColor.a); }
            inline static void Draw(const Ref<VertexArray>& vVertexArray) { glDrawElements(GL_TRIANGLES, vVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr); }

            static void Begin();
            static void End();

            static void InitStoragePoint(const sstr& vName);
            static void PushToStoragePoint(const sstr& vName, const Ref<VertexArray>& vVertexArray);
            static void RemoveStoragePoint(const sstr& vName);
            static void DrawFromStoragePoint(const sstr& vName);

        private:
            static std::unordered_map<sstr, svec<Ref<VertexArray>>> mStoragePoint;
    };

}
