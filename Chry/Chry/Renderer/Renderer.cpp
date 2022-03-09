#include "pch.hpp"
#include "Renderer.hpp"

namespace Chry
{
    Renderer::SceneData* Renderer::mRendererElements = new Renderer::SceneData;

    void Renderer::Begin(OrthographicCamera& vCamera)
    {
        mRendererElements->OrthographicCameraViewProjectionMatrix = vCamera.GetViewProjectionMatrix();
    }

    void Renderer::Submit(const Ref<VertexArray> &vVertexArray, const Ref<Shader> &vShader, const glm::mat4& vTransform)
    {
        vShader->Bind();
        vVertexArray->Bind();

        vShader->SetMat4("uViewProjectionMatrix", mRendererElements->OrthographicCameraViewProjectionMatrix);
        vShader->SetMat4("uTransform", vTransform);

        Renderer::Draw(vVertexArray);
    }

    void Renderer::End()
    {

    }
}
