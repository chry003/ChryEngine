#include <Chry.hpp>

class TriangleWithNoTexture : public Chry::Layer
{
    public:

        TriangleWithNoTexture()
        {

        }

        void OnAttach() override
        {

            float vert[] = {
                //    Position  //      //        Color       //
                -0.5f, -0.5f, 0.0f,     -0.5f, -0.5f, 0.0f, 1.0f,
                 0.5f, -0.5f, 0.0f,      0.5f, -0.5f, 0.0f, 1.0f,
                 0.5f,  0.5f, 0.0f,      0.5f,  0.5f, 0.0f, 1.0f,
                -0.5f,  0.5f, 0.0f,     -0.5f,  0.5f, 0.0f, 1.0f
            };

            ui indices[] = {
                0, 1, 2,
                2, 3, 0
            };

            mShader = Chry::MakeRef<Chry::Shader>("CommonShader", "./Assets/GLSL/main.vert", "./Assets/GLSL/main.frag");
            mVertexArray = Chry::MakeRef<Chry::VertexArray>();
            mVertexBuffer = Chry::MakeRef<Chry::VertexBuffer>(vert, sizeof(vert), Chry::DrawType::STATIC);
            mIndexBuffer = Chry::MakeRef<Chry::IndexBuffer>(indices, sizeof(indices), Chry::DrawType::STATIC);

            Chry::BufferLayout BufferLayoutTriangle = Chry::BufferLayout({
                        { Chry::ShaderDataType::Float3, "vPosition" },
                        { Chry::ShaderDataType::Float4, "vColor" }
                    });

            mShader->Bind();
            mVertexArray->Bind();
            mVertexBuffer->Bind();
            mIndexBuffer->Bind();

            mVertexBuffer->SetBufferLayout(BufferLayoutTriangle);
            mVertexArray->AddVertexBuffer(mVertexBuffer);
            mVertexArray->SetIndexBuffer(mIndexBuffer);

            Chry::Renderer::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
            Chry::Renderer::InitStoragePoint("Test");
            Chry::Renderer::PushToStoragePoint("Test", mVertexArray);
        }

        void OnUpdate() override
        {
            Chry::Renderer::DrawFromStoragePoint("Test");
        }

    private:
        Chry::Ref<Chry::Shader> mShader;
        Chry::Ref<Chry::VertexBuffer> mVertexBuffer;
        Chry::Ref<Chry::IndexBuffer> mIndexBuffer;
        Chry::Ref<Chry::VertexArray> mVertexArray;

};

class TriangleWithTexture : public Chry::Layer
{
    public:
        TriangleWithTexture()
        {

        }

        void OnAttach() override
        {
            float vert[] = {
                //    Position  //      //        Color       //
                 0.5f,  0.5f, 0.0f,     -0.5f, -0.5f, 0.0f, 1.0f,   1.0f, 1.0f,
                 0.5f, -0.5f, 0.0f,      0.5f, -0.5f, 0.0f, 1.0f,   1.0f, 0.0f,
                -0.5f, -0.5f, 0.0f,      0.5f,  0.5f, 0.0f, 1.0f,   0.0f, 0.0f,
                -0.5f,  0.5f, 0.0f,     -0.5f,  0.5f, 0.0f, 1.0f,   0.0f, 1.0f
            };

            ui indices[] = {
                0, 1, 2,
                2, 3, 0
            };

            mShader = Chry::MakeRef<Chry::Shader>("CommonShader", "./Assets/GLSL/main.vert", "./Assets/GLSL/texture.frag");
            mVertexArray = Chry::MakeRef<Chry::VertexArray>();
            mVertexBuffer = Chry::MakeRef<Chry::VertexBuffer>(vert, sizeof(vert), Chry::DrawType::STATIC);
            mIndexBuffer = Chry::MakeRef<Chry::IndexBuffer>(indices, sizeof(indices), Chry::DrawType::STATIC);
            mTexture = Chry::MakeRef<Chry::Texture2D>("./Assets/img/1.png");

            Chry::BufferLayout BufferLayoutTriangle = Chry::BufferLayout({
                        { Chry::ShaderDataType::Float3, "vPosition" },
                        { Chry::ShaderDataType::Float4, "vColor" },
                        { Chry::ShaderDataType::Float2, "vTexCoords" }
                    });

            mShader->Bind();
            mVertexArray->Bind();
            mVertexBuffer->Bind();
            mIndexBuffer->Bind();
            mTexture->Bind();

            mVertexBuffer->SetBufferLayout(BufferLayoutTriangle);
            mVertexArray->AddVertexBuffer(mVertexBuffer);
            mVertexArray->SetIndexBuffer(mIndexBuffer);

            Chry::Renderer::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
            Chry::Renderer::InitStoragePoint("TextureTest");
            Chry::Renderer::PushToStoragePoint("TextureTest", mVertexArray);
        }

        void OnUpdate() override
        {
            Chry::Renderer::DrawFromStoragePoint("TextureTest");
        }

    private:
        Chry::Ref<Chry::Shader> mShader;
        Chry::Ref<Chry::VertexBuffer> mVertexBuffer;
        Chry::Ref<Chry::IndexBuffer> mIndexBuffer;
        Chry::Ref<Chry::VertexArray> mVertexArray;
        Chry::Ref<Chry::Texture2D> mTexture;
};

class Sandbox : public Chry::Application
{
    public:
        Sandbox()
        {
            // PushLayer(new TriangleWithNoTexture());
            PushLayer(new TriangleWithTexture());
        }
        ~Sandbox()
        {
        }
};

Chry::Application* Chry::CreateApplication()
{
    return new Sandbox();
}
