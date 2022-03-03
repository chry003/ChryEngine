#include <Chry.hpp>

class TriangleLayer : public Chry::Layer
{
    public:
        TriangleLayer()
        {

        }

        void OnAttach() override
        {
            mShader = Unq<Shader>("Common_Shader", "vertexShader.vert", "fragmentShader.frag");
            mTexture = Unq<Texture>("Triangle_Texture", "triangel.png");
            mRendererable = Unq<Rendererable>();

            mRendererable->addVertices(Chry::Type::FLOAT, 
                        {
                            -0.5f,  0.5f, 0.0f,
                             0.5f, -0.5f, 0.0f,
                            -0.5f,  0.5f, 0.0f
                        }
                    );
            mRendererable->addIndices(Chry::Type::FLOAT,
                        {
                            0, 1, 2,
                            2, 1, 0
                        }
                    );
            mRendererable->addBufferLayout(
                        {
                            { Chry::ShaderDataType::Float3, "uPos" },
                            { Chry::ShaderDataType::Float4, "uTex" }
                        }
                    );

            mRendererable->initRenderData(mShader, nullptr);

            Chry::RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
            Chry::Renderer::Begin(mCamera);

            // Create Storage Point to store Rendererable items
            Chry::Renderer::initStoragePoint("TrianglesStoragePoint");
            Chry::Renderer::pushToStoragePoint("TrianglesStoragePoint", mRendererable);
        }

        void OnUpdate(float dt) override
        {
            // Draw Items from Storage Point
            Chry::Renderer::drawFromStoragePoint("TrianglesStoragePoint");

            // OR Draw Without Storage Point
            Chry::Renderer::Draw(mRendererable);
        }

        void OnDetach() override
        {
            Chry::Renderer::End();
        }

    private:
        Chry::OrthographicCamera mCamera;
        Chry::Shader mShader;
        Chry::Texture mTexture;
        Chry::Rendererable mRendererable;
};

class Sandbox : public Application
{
    public:
        Sandbox()
        {
            PushLayer(new TriangleLayer);
        }
};


Chry::Application* Chry::CreateApplication()
{
    return new Sandbox();
}
