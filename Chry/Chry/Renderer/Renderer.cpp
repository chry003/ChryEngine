#include "pch.hpp"
#include "Renderer.hpp"

namespace Chry
{
    Renderer::SceneData* Renderer::mRendererElements = new Renderer::SceneData;

    void Renderer::Begin(OrthographicCamera& vCamera)
    {
        mRendererElements->OrthographicCameraViewProjectionMatrix = vCamera.GetViewProjectionMatrix();
    }

    void Renderer::Submit(const Ref<VertexArray> &vVertexArray, const Ref<Material>& vMaterial, const glm::mat4& vTransform)
    {
        vMaterial->GetShader()->Bind();
        vVertexArray->Bind();

        //vShader->SetMat4("uViewProjectionMatrix", mRendererElements->OrthographicCameraViewProjectionMatrix);
        //vShader->SetMat4("uTransform", vTransform);

        vMaterial->SetUniformValue("uViewProjectionMatrix", mRendererElements->OrthographicCameraViewProjectionMatrix);
        vMaterial->SetUniformValue("uTransform", vTransform);
        vMaterial->UpdateUniforms();

        Renderer::Draw(vVertexArray);
    }

    void Renderer::End()
    {

    }
}
