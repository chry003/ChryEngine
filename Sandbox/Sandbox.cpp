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

            mShader = Chry::MakeRef<Chry::Shader>("CommonShader", "./Chry/shader/Common.vert", "./Chry/shader/Common.frag");
            mVertexArray = Chry::MakeRef<Chry::VertexArray>();
            mVertexBuffer = Chry::MakeRef<Chry::VertexBuffer>(vert, sizeof(vert), Chry::DrawType::DYNAMIC);
            mIndexBuffer = Chry::MakeRef<Chry::IndexBuffer>(indices, sizeof(indices), Chry::DrawType::DYNAMIC);
            mTexture = Chry::MakeRef<Chry::Texture2D>("./Assets/img/3.jpg");
            mMaterialBlue = Chry::MakeRef<Chry::Material>(mShader, mTexture);

            Chry::BufferLayout BufferLayoutTriangle = Chry::BufferLayout({
                        { Chry::ShaderDataType::Float3, "aPosition" },
                        { Chry::ShaderDataType::Float4, "aColor" },
                        { Chry::ShaderDataType::Float2, "aTexCoords" }
                    });

            mShader->Bind();
            mVertexArray->Bind();
            mVertexBuffer->Bind();
            mIndexBuffer->Bind();
            mTexture->Bind();
            
            mMaterialBlue->SetUniformValue("uTexture", 0);
            mMaterialBlue->SetUniformValue("uTextured", 1);
            mMaterialRed = Chry::MakeRef<Chry::Material>(mMaterialBlue);

            mVertexBuffer->SetBufferLayout(BufferLayoutTriangle);
            mVertexArray->AddVertexBuffer(mVertexBuffer);
            mVertexArray->SetIndexBuffer(mIndexBuffer);

            Chry::Renderer::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
        }

        void OnUpdate(float dt) override
        {
            {
                if (Chry::Input::IsKeyPressed(Chry::Key::A))
                    obj1.x += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::D))
                    obj1.x -= speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::S))
                    obj1.y += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::W))
                    obj1.y -= speed * (-1);
            }
            {
                if (Chry::Input::IsKeyPressed(Chry::Key::Left))
                    obj2.x += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::Right))
                    obj2.x -= speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::Down))
                    obj2.y += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::Up))
                    obj2.y -= speed * (-1);
            }

            Chry::Renderer::Begin(mCamera);
            Chry::Renderer::Submit(mVertexArray, mMaterialBlue, glm::translate(glm::mat4(1.0f), obj1));
            Chry::Renderer::Submit(mVertexArray, mMaterialRed, glm::translate(glm::mat4(1.0f), obj2));
        }

    private:
        Chry::OrthographicCamera mCamera;
        Chry::Ref<Chry::Shader> mShader;
        Chry::Ref<Chry::VertexBuffer> mVertexBuffer;
        Chry::Ref<Chry::IndexBuffer> mIndexBuffer;
        Chry::Ref<Chry::VertexArray> mVertexArray;
        Chry::Ref<Chry::Texture2D> mTexture;
        Chry::Ref<Chry::Material> mMaterialBlue;
        Chry::Ref<Chry::Material> mMaterialRed;

        f32 speed = 0.05f;

        glm::vec3 obj1 = {  1.8f, 0.0f, 0.0f };
        glm::vec3 obj2 = { -1.8f, 0.0f, 0.0f };
};

class SpriteTesting : public Chry::Layer
{
    public:
        SpriteTesting()
            : mCamera(-4.0f, 4.0f, -3.0f, 3.0f)
        {
        }

        void OnAttach() override
        {
            mShader = Chry::MakeRef<Chry::Shader>("SpriteShader", "./Chry/shader/Common.vert", "./Chry/shader/Common.frag");
            mTexture = Chry::MakeRef<Chry::Texture2D>("./Assets/img/3.jpg");
            mMaterial = Chry::MakeRef<Chry::Material>(mShader);
            mSprite = Chry::MakeRef<Chry::Sprite>(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(0.7f, 0.2f, 0.3f, 1.0f), mMaterial);
            mSprite2 = Chry::MakeRef<Chry::Sprite>(glm::vec3(-1.5f, 1.5f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(0.7f, 0.2f, 0.3f, 1.0f), mMaterial, mTexture);

            mSprite->Bind();
            mSprite2->Bind();
        }

        void OnUpdate(float dt) override
        {
            {
                if (Chry::Input::IsKeyPressed(Chry::Key::A))
                    obj1.x += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::D))
                    obj1.x -= speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::S))
                    obj1.y += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::W))
                    obj1.y -= speed * (-1);
            }
            {
                if (Chry::Input::IsKeyPressed(Chry::Key::Left))
                    obj2.x += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::Right))
                    obj2.x -= speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::Down))
                    obj2.y += speed * (-1);
                else if(Chry::Input::IsKeyPressed(Chry::Key::Up))
                    obj2.y -= speed * (-1);
            }

            Chry::Renderer::Begin(mCamera);

            mSprite->SetPosition(obj1);
            mSprite2->SetPosition(obj2);

            mSprite->Draw();
            mSprite2->Draw();
        }

    private:
        Chry::OrthographicCamera mCamera;
        Chry::Ref<Chry::Shader> mShader;
        Chry::Ref<Chry::Texture2D> mTexture;
        Chry::Ref<Chry::Material> mMaterial;
        Chry::Ref<Chry::Sprite> mSprite;
        Chry::Ref<Chry::Sprite> mSprite2;

        glm::vec3 obj1 = glm::vec3(1.0f);
        glm::vec3 obj2 = glm::vec3(1.0f);
        float speed = 0.1f;
};

class TestGame : public Chry::Layer
{
    public:
        TestGame()
            : mCamera(0.0f, 4.0f, 0.0f, 3.0f)
        {
        }

        void OnAttach() override
        {
            mShader = Chry::MakeRef<Chry::Shader>("GameShader", "./Chry/shader/Common.vert", "./Chry/shader/Common.frag");
            mMaterial = Chry::MakeRef<Chry::Material>(mShader);

            // Player
            mPlayerTexture = Chry::MakeRef<Chry::Texture2D>("./Sandbox/assets/sprites/bluebird-midflap.png");
            mPlayer = Chry::MakeRef<Chry::Sprite>(mPlayerPosition, mPlayerSize, mPlayerColor, mMaterial, mPlayerTexture);

            mPlayer->Bind();

            Chry::Renderer::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });

            mPlayer->SetRotation(0.0f);
            // mPlayer->SetScale(glm::vec3(-1.0f, 1.0f, 1.0f));
        }

        void OnUpdate(float dt) override
        {
            Chry::Renderer::Begin(mCamera);

            CLIENT_LOG_INFO("Speed: {}", mSpeed);

            {
                if(Chry::Input::IsKeyPressed(Chry::Key::Space))
                {
                    if(mSpeed > -1.0f)
                        mSpeed -= 2.0f;
                    else
                        mSpeed += mGravity;
                }
            }

            mSpeed += mGravity;
            mPlayerPosition.y -= mSpeed * dt;

            mPlayer->SetPosition(mPlayerPosition);
            mPlayer->Draw();

        }

    private:
        Chry::OrthographicCamera mCamera;

        Chry::Ref<Chry::Shader> mShader;
        Chry::Ref<Chry::Material> mMaterial;

        // Player
        Chry::Ref<Chry::Texture2D> mPlayerTexture;
        Chry::Ref<Chry::Sprite> mPlayer;
        glm::vec3 mPlayerPosition = glm::vec3(0.2f, 1.5f, 0.0f);
        glm::vec2 mPlayerSize = glm::vec2(0.3f);
        glm::vec4 mPlayerColor = glm::vec4(1.0f);

        float mSpeed = 0.2f;
        float mGravity = 0.02f;
};

class Sandbox : public Chry::Application
{
    public:
        Sandbox()
        {
            // PushLayer(new TriangleWithTexture());
            // PushLayer(new SpriteTesting());
            PushLayer(new TestGame());
        }
        ~Sandbox()
        {
        }
};

Chry::Application* Chry::CreateApplication()
{
    return new Sandbox();
}
