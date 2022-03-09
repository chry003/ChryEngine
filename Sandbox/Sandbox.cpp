#include <Chry.hpp>

class TriangleWithTexture : public Chry::Layer
{
    public:
        TriangleWithTexture()
            : mCamera(-4.0f, 4.0f, -3.0f, 3.0f)
        {

        }

        void OnAttach() override
        {
            f32 vert[] = {
                //    Position  //      //        Color       //       // Texture //
                -0.5f, -0.5f, 0.0f,     -0.5f, -0.5f, 0.0f, 1.0f,       0.0f, 0.0f,
                 0.5f, -0.5f, 0.0f,      0.5f, -0.5f, 0.0f, 1.0f,       1.0f, 0.0f,
                 0.5f,  0.5f, 0.0f,      0.5f,  0.5f, 0.0f, 1.0f,       1.0f, 1.0f,
                -0.5f,  0.5f, 0.0f,     -0.5f,  0.5f, 0.0f, 1.0f,       0.0f, 1.0f
            };

            ui indices[] = {
                0, 1, 2,
                2, 3, 0
            };

            mShader = Chry::MakeRef<Chry::Shader>("CommonShader", "./Assets/GLSL/main.vert", "./Assets/GLSL/texture.frag");
            mVertexArray = Chry::MakeRef<Chry::VertexArray>();
            mVertexBuffer = Chry::MakeRef<Chry::VertexBuffer>(vert, sizeof(vert), Chry::DrawType::DYNAMIC);
            mIndexBuffer = Chry::MakeRef<Chry::IndexBuffer>(indices, sizeof(indices), Chry::DrawType::DYNAMIC);
            mTexture = Chry::MakeRef<Chry::Texture2D>("./Assets/img/3.jpg");

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

            mShader->SetInt("mTexture", 0);

            mVertexBuffer->SetBufferLayout(BufferLayoutTriangle);
            mVertexArray->AddVertexBuffer(mVertexBuffer);
            mVertexArray->SetIndexBuffer(mIndexBuffer);

            Chry::Renderer::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
        }

        void OnUpdate() override
        {
            {
                if (Chry::Input::IsKeyPressed(Chry::Key::A))
                    pos.x += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::D))
                    pos.x -= speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::S))
                    pos.y += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::W))
                    pos.y -= speed * (-1);
            }

            Chry::Renderer::Begin(mCamera);
            Chry::Renderer::Submit(mVertexArray, mShader, glm::translate(glm::mat4(1.0f), pos));
        }

    private:
        Chry::OrthographicCamera mCamera;
        Chry::Ref<Chry::Shader> mShader;
        Chry::Ref<Chry::VertexBuffer> mVertexBuffer;
        Chry::Ref<Chry::IndexBuffer> mIndexBuffer;
        Chry::Ref<Chry::VertexArray> mVertexArray;
        Chry::Ref<Chry::Texture2D> mTexture;

        glm::vec3 pos;
        f32 speed = 0.05f;
};

class Sandbox : public Chry::Application
{
    public:
        Sandbox()
        {
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
