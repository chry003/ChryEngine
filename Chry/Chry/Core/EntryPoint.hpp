#pragma once

extern Chry::Application* Chry::CreateApplication();

int main(int argc, char** argv)
{
    Chry::Log::Init();
    CORE_LOG_WARN("[APPLICATION]: initialized!");
    auto app = Chry::CreateApplication();
    app->Run();
    delete app;
}
