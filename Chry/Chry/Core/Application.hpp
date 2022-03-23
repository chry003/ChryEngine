#pragma once

#include "Graphics/Window.hpp"
#include "Event/Event.hpp"
#include "Layer/LayerStack.hpp"
#include "Timer.hpp"

namespace Chry
{

    class Application
    {
        public:
            Application();
            virtual ~Application();
            
            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);

            void Run();

        private:
            static Application* s_Instance;
            LayerStack mLayerStack;
    };

    Application* CreateApplication();

}
