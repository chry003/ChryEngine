#pragma once

#include "Core/Base.hpp"
#include "Renderer/Buffer.hpp"
#include "Renderer/Renderer.hpp"
#include "Graphics/Shader.hpp"
#include "Graphics/Material.hpp"
#include "Graphics/Texture.hpp"

namespace Chry
{

    class Sprite
    {
        public:
            Sprite(const glm::vec3& vPosition, const glm::vec2& vSize, const glm::vec4& vColor, const Ref<Material>& vMaterial, const Ref<Texture2D>& vTexture = nullptr);
            ~Sprite();

            void Bind() const;
            void Draw() const;

            inline void SetPosition(const glm::vec3& vPosition) { mPosition = vPosition; }
            inline void SetSize(const glm::vec2& vSize) { mSize = vSize; }
            inline void SetColor(const glm::vec4& vColor) { mColor = vColor; }
            inline void SetTexture(const Ref<Texture2D>& vTexture) { mTexture = vTexture; }

            inline const glm::vec3& GetPosition() const { return mPosition; }
            inline const glm::vec2& GetSize() const { return mSize; }
            inline const glm::vec4& GetColor() const { return mColor; }
            inline const Ref<Texture2D>& GetTexture() const { return mTexture; }

        private:
            void InitDrawData();

        private:
            glm::vec3 mPosition;
            glm::vec2 mSize;
            glm::vec4 mColor;

            Ref<Material> mMaterial;
            Ref<Texture2D> mTexture;
            Ref<VertexArray> mVertexArray;
    };

}
