#pragma once

#include "Core/Base.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

namespace Chry
{

    class Texture2D
    {
        public:
            Texture2D(const sstr& vPath);
            ~Texture2D();

            void Bind() const;
            void Unbind() const;

        private:
            u32 mTextureID;
    };

}
