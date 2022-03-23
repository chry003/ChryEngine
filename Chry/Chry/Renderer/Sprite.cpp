#include "pch.hpp"
#include "Sprite.hpp"

namespace Chry
{

    Sprite::Sprite(const glm::vec3& vPosition, const glm::vec2& vSize, const glm::vec4& vColor, const Ref<Material>& vMaterial, const Ref<Texture2D>& vTexture)
        : mPosition(vPosition), mSize(vSize), mColor(vColor), mMaterial(vMaterial), mTexture(vTexture)
    {
        InitDrawData();
        RecalculateMatrix();
    }
    
    Sprite::~Sprite()
    {

    }

    void Sprite::Bind() const
    {
        mVertexArray->Bind();
        mMaterial->GetShader()->Bind();

        if(mTexture)
        {
            mMaterial->SetTexture(mTexture);
            mMaterial->GetTexture()->Bind();
        }

    }

    void Sprite::Draw() const
    {
        if(mTexture)
        {
            mMaterial->SetTexture(mTexture);
            mMaterial->GetTexture()->Bind();
            mMaterial->SetUniformValue("uTexture", 0);
            mMaterial->SetUniformValue("uTextured", 1);
        }
        else
        {
            mMaterial->SetTexture(mTexture);
            mMaterial->SetUniformValue("uTextured", 0);
        }

        mMaterial->SetUniformValue("uColor", mColor);

        Renderer::Submit(mVertexArray, mMaterial, mTransformationMatrix);
    }

    void Sprite::InitDrawData()
    {
        f32 vert[] = {
             0.0f,      0.0f,       0.0f,       mColor.r, mColor.g, mColor.b, mColor.a,         0.0f, 0.0f,
             0.0f,      mSize.x,    0.0f,       mColor.r, mColor.g, mColor.b, mColor.a,         0.0f, 1.0f,
             mSize.y,   mSize.x,    0.0f,       mColor.r, mColor.g, mColor.b, mColor.a,         1.0f, 1.0f,
             mSize.y,   0.0f,       0.0f,       mColor.r, mColor.g, mColor.b, mColor.a,         1.0f, 0.0f
        };

        ui indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        mVertexArray = MakeRef<VertexArray>();

        Ref<VertexBuffer> mVertexBuffer = MakeRef<VertexBuffer>(vert, sizeof(vert), DrawType::DYNAMIC);
        Ref<IndexBuffer> mIndexBuffer = MakeRef<IndexBuffer>(indices, sizeof(indices), DrawType::DYNAMIC);

        BufferLayout BufferLayoutSprite = BufferLayout({
                    { ShaderDataType::Float3, "aPosition" },
                    { ShaderDataType::Float4, "aColor" },
                    { ShaderDataType::Float2, "aTexCoords" }
                });

        mVertexArray->Bind();
        mVertexBuffer->Bind();
        mIndexBuffer->Bind();

        mVertexBuffer->SetBufferLayout(BufferLayoutSprite);
        mVertexArray->AddVertexBuffer(mVertexBuffer);
        mVertexArray->SetIndexBuffer(mIndexBuffer);
    }

    void Sprite::RecalculateMatrix()
    {
        mTransformationMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::rotate(glm::mat4(1.0f), mRotation, glm::vec3(0.0f, 0.0f, 1.0f));
        mTransformationMatrix *= glm::scale(glm::mat4(1.0f), mScale);
    }
}
