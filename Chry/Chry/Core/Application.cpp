#include "pch.hpp"
#include "Application.hpp"

#include "Graphics/Shader.hpp"
#include "Renderer/Buffer.hpp"

namespace Chry
{

    Application::Application()
    {
        Window::Init();
        Window::SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
        // Set Window VSync to false as it doesn't have constant time to handle loop.
        // Window::SetWindowVSync(false);
        
        timer.TimerInit();
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        // dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        CORE_LOG_INFO("{0}", e.ToString());
        
        for (auto it = mLayerStack.end(); it != mLayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if(e.Handled())
                break;
        }
    }

    void Application::PushLayer(Layer* layer) 
    {
        mLayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay) 
    {
        mLayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Application::Run()
    {
    	while(!Window::isWindowClosed())
        {
            Window::OnClear();

            for (Layer* layer : mLayerStack)
            {
                layer->OnUpdate(timer.DeltaTime());
            }

            Window::OnUpdate();

            timer.Tick();
        }
    }

    Application::~Application()
    {
    	Window::Terminate();
    }
}
