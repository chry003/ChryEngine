#pragma once

#include "Core/Base.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

#include <glm/glm.hpp>

namespace Chry
{

    class Material
    {
        public:
            Material(const Ref<Shader>& vShader, const Ref<Texture2D>& vTexture = nullptr);
            Material(const Ref<Material>& vMaterialSystem);
            ~Material();

            void SetShader(const Ref<Shader>& vShader);
            void SetTexture(const Ref<Texture2D>& vTexture);

            inline const Ref<Shader>& GetShader() const { return mShader; }
            inline const Ref<Texture2D>& GetTexture() const { return mTexture; }

            void UpdateUniforms();

#define GETUNIFORMVALUE(mapName, defReturn)\
            const auto& it = mapName.find(name);\
            if(it != mapName.end())\
            {\
                return it->second;\
            }\
            return defReturn;


		template<typename T>
		inline T GetUniformValue(const std::string& name) const
		{
			if constexpr (std::is_same<T, int>()) { GETUNIFORMVALUE(mUniformInts, 0) }
			else if constexpr (std::is_same<T, float>()) { GETUNIFORMVALUE(mUniformFloats, 0.f) }
			else if constexpr (std::is_same<T, glm::vec2>()) { GETUNIFORMVALUE(mUniformFloat2s, glm::vec2(0.f)) }
			else if constexpr (std::is_same<T, glm::vec3>()) { GETUNIFORMVALUE(mUniformFloat3s, glm::vec3(0.f)) }
			else if constexpr (std::is_same<T, glm::vec4>()) { GETUNIFORMVALUE(mUniformFloat4s, glm::vec4(0.f)) }
			else if constexpr (std::is_same<T, glm::mat4>()) { GETUNIFORMVALUE(mUniformMat4s, glm::mat4(1.f)) }
			else
			{
                int res = std::is_same<T, std::false_type>();
                ASSERT(res, "Unsupported data type.")
			}
		}

#undef GETUNIFORMVALUE

		template<typename T>
		inline void SetUniformValue(const std::string& name, const T& val)
		{
			if constexpr (std::is_same<T, int>()) { mUniformInts[name] = val; }
			else if constexpr (std::is_same<T, float>()) { mUniformFloats[name] = val; }
			else if constexpr (std::is_same<T, glm::vec2>()) { mUniformFloat2s[name] = val; }
			else if constexpr (std::is_same<T, glm::vec3>()) { mUniformFloat3s[name] = val; }
			else if constexpr (std::is_same<T, glm::vec4>()) { mUniformFloat4s[name] = val; }
			else if constexpr (std::is_same<T, glm::mat4>()) { mUniformMat4s[name] = val; }
			else
			{
                int res = std::is_same<T, std::false_type>();
                ASSERT(res, "Unsupported data type.")
			}
		}

        private:
            Ref<Shader> mShader;
            Ref<Texture2D> mTexture;

            sumap<sstr, int> mUniformInts;
            sumap<sstr, float> mUniformFloats;
            sumap<sstr, glm::vec2> mUniformFloat2s;
            sumap<sstr, glm::vec3> mUniformFloat3s;
            sumap<sstr, glm::vec4> mUniformFloat4s;
            sumap<sstr, glm::mat4> mUniformMat4s;
    };

}
