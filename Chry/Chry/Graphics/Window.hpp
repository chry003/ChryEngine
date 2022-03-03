#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Core/Base.hpp"
#include "Core/Log.hpp"
#include "Event/Event.hpp"

namespace Chry 
{

    enum class WindowMode
    {
        FULLSCREEN = 0,
        WINDOWED = 1
    };

    struct WindowProps
    {
        sstr Title;
        u32 Width;
        u32 Height;
        WindowMode WM;
        bool VSync;

        WindowProps(
                    const sstr& vTitle = "Chry Engine",
                    const u32& vWidth = 800,
                    const u32& vHeight = 600,
                    const WindowMode& vWM = WindowMode::WINDOWED,
                    const bool& vVSync = true
                )
            : Title(vTitle),
              Width(vWidth),
              Height(vHeight),
              WM(vWM),
              VSync(vVSync)
        {
        }
    };

    class Window
    {
        public:
            using EventCallbackFn = sfun<void(Event&)>;

            static void Init(const WindowProps& props = WindowProps());
            static void Terminate();

            static void OnClear();
            static void OnUpdate();
            
            static void MakeWindowContextCurrent();

            static void WindowOnFocus();
            static void MaximizeWindow();
            static void MinimizeWindow();
            static void RestoreWindow();
            static void CloseWindow();

		    static void SetEventCallback(const EventCallbackFn& callback) { mWindowData.EventCallback = callback; };

            static void SetWindowHeight(const u32& vHeight);
            static void SetWindowWidth(const u32& vWidth);
            static void SetWindowSize(const glm::vec2& vSize);
            static void SetWindowTitle(const sstr& vTitle);
            static void SetWindowVSync(const bool& enabled);

            inline static const sstr& GetWindowTitle() { return mWindowData.Title; }
            inline static u32 GetWindowWidth() { return mWindowData.Size.x; }
            inline static u32 GetWindowHeight() { return mWindowData.Size.y; }
            inline static const glm::vec2& GetWindowSize() { return mWindowData.Size; }
            inline static bool isWindowClosed() { return glfwWindowShouldClose(mWindow); }
            inline static bool isVSync() { return mWindowData.VSync; }
            inline static void* GetNativeWindow() { return mWindow; }

        private:
            struct WindowData
            {
                sstr Title;
                glm::vec2 Size;
                bool Closed;
                bool VSync;

			    EventCallbackFn EventCallback;
            };

        private:
            static GLFWwindow* mWindow;
            static WindowData mWindowData;

    };

}
