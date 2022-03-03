#include "Window.hpp"

#include "Event/ApplicationEvent.hpp"
#include "Event/KeyEvent.hpp"
#include "Event/MouseEvent.hpp"

namespace Chry 
{

    static bool isGLFWWindowIsCreated = false;
    GLFWwindow *Window::mWindow = nullptr;
    Window::WindowData Window::mWindowData;

    void Window::Init(const WindowProps &props)
    {
        // INIT props to Window data
        mWindowData.Title = props.Title;
        mWindowData.Size.x = (float)props.Width;
        mWindowData.Size.y = (float)props.Height;
        mWindowData.VSync = true;
        mWindowData.Closed = false;

        // Create Window if not created
        if(!isGLFWWindowIsCreated)
        {
            int glfwWindowINITresult = glfwInit();
            isGLFWWindowIsCreated = true;
            ASSERT(glfwWindowINITresult, "Failed to init GLFW!!");
        }


        // GLFW window HINTS

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


        // Create Window

        mWindow = glfwCreateWindow(
                    (int)mWindowData.Size.x,
                    (int)mWindowData.Size.y,
                    mWindowData.Title.c_str(),
                    nullptr,
                    nullptr
                );

        glfwSetWindowUserPointer(mWindow, &mWindowData);

        // Make Context Current
        MakeWindowContextCurrent();

        // GLAD setup
        int gladINITStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        ASSERT(gladINITStatus, "Failed to init GLAD");
        
        glViewport(0, 0, (int)mWindowData.Size.x, (int)mWindowData.Size.y);

        SetWindowVSync(true);
 
		//////////////////////////////////////////////
		//				Window Event 				//
		//////////////////////////////////////////////

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Closed = true;
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Size.x = width;
			data.Size.y = height;

			glViewport(0, 0, (int)width, (int)height);

			WindowSizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowPosCallback(mWindow, [](GLFWwindow* window, int xpos, int ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowPosEvent event(xpos, ypos);
			data.EventCallback(event);
		});

		glfwSetWindowRefreshCallback(mWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowRefreshEvent event;
			data.EventCallback(event);

		});

		glfwSetWindowFocusCallback(mWindow, [](GLFWwindow* window, int focused)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowFocusedEvent event(focused);
			data.EventCallback(event);
		});

		//////////////////////////////////////////////
		//				Keyboard Event 				//
		//////////////////////////////////////////////

        glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
            	case GLFW_PRESS:
            	{
            		KeyPressedEvent event(key, 0);
            		data.EventCallback(event);
            		break;
            	}
            	case GLFW_RELEASE:
            	{
            		KeyReleasedEvent event(key);
            		data.EventCallback(event);
            		break;
            	}
            	case GLFW_REPEAT:
            	{
            		KeyPressedEvent event(key, 1);
            		data.EventCallback(event);
            		break;
            	}
            }

        });


		//////////////////////////////////////////////
		//				Mouse Event 				//
		//////////////////////////////////////////////

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xpos, double ypos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MousePositionEvent event((float)xpos, (float)ypos);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
          	{
          		case GLFW_PRESS:
          		{
		            MouseButtonPressedEvent event(button);
		            data.EventCallback(event);
		            break;
          		}
          		case GLFW_RELEASE:
          		{
		            MouseButtonReleasedEvent event(button);
		            data.EventCallback(event);
		            break;
          		}
          	}
        });

        glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xoffset, double yoffset)
        {
        	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        	MouseScrollEvent event((float)xoffset, (float)yoffset);
        	data.EventCallback(event);
        });
    }

    void Window::Terminate()
    {
        glfwDestroyWindow(mWindow);
    }

    void Window::MakeWindowContextCurrent()
    {
        glfwMakeContextCurrent(mWindow);
    }

    void Window::OnClear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(mWindow);
    }

    void Window::WindowOnFocus(){}

    void Window::MaximizeWindow(){}

    void Window::MinimizeWindow(){}

    void Window::RestoreWindow(){}

    void Window::CloseWindow(){}

    void Window::SetWindowHeight(const u32& vHeight){}
    
    void Window::SetWindowWidth(const u32& vWidth){}
    
    void Window::SetWindowSize(const glm::vec2& vSize){}
    
    void Window::SetWindowTitle(const sstr& vTitle){}
    
    void Window::SetWindowVSync(const bool& enabled)
    {
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        mWindowData.VSync = enabled;
    }
}
