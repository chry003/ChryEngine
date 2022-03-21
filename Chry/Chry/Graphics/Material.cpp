#include "pch.hpp"
#include "Material.hpp"

namespace Chry
{
    Material::Material(const Ref<Shader>& vShader, const Ref<Texture2D>& vTexture)
        : mShader(vShader)
        , mTexture(vTexture)
    {
        ASSERT(mShader, "Cannot assign nullptr to MATERIAL::SHADER")
    }

    Material::Material(const Ref<Material>& vMaterialSystem)
    {
        mShader = vMaterialSystem->mShader;
        mTexture = vMaterialSystem->mTexture;

        mUniformInts = vMaterialSystem->mUniformInts;
        mUniformFloats = vMaterialSystem->mUniformFloats;
        mUniformFloat2s = vMaterialSystem->mUniformFloat2s;
        mUniformFloat3s = vMaterialSystem->mUniformFloat3s;
        mUniformFloat4s = vMaterialSystem->mUniformFloat4s;
        mUniformMat4s = vMaterialSystem->mUniformMat4s;
    }

    Material::~Material()
    {

    }

    void Material::SetShader(const Ref<Shader>& vShader)
    {
        if(vShader)
            mShader = vShader;
        else
            ASSERT(vShader, "Cannot assign nullptr to MATERIAL::SHADER")
    }

    void Material::SetTexture(const Ref<Texture2D>& vTexture)
    {
        mTexture = vTexture;
    }

    void Material::UpdateUniforms()
    {

#define UPLOADUNIFORM(shader, uniformtype, uniformtypefunc)\
        for(const auto& it : uniformtype)\
        {\
            shader->uniformtypefunc(it.first, it.second);\
        }

        UPLOADUNIFORM(mShader, mUniformInts, SetInt);
        UPLOADUNIFORM(mShader, mUniformFloats, SetFloat);
        UPLOADUNIFORM(mShader, mUniformFloat2s, SetFloat2);
        UPLOADUNIFORM(mShader, mUniformFloat3s, SetFloat3);
        UPLOADUNIFORM(mShader, mUniformFloat4s, SetFloat4);
        UPLOADUNIFORM(mShader, mUniformMat4s, SetMat4);

#undef UPLOADUNIFORM
    }
}
