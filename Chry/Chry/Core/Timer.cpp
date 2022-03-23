#include "pch.hpp"
#include "Timer.hpp"
#include "GLFW/glfw3.h"

namespace Chry
{

    void Timer::TimerInit()
    {
        mLastFrame = 0.0f;
        mDeltaTime = 0.0f;
    }

    void Timer::Tick()
    {
        mDeltaTime = glfwGetTime() - mLastFrame;
        mLastFrame = glfwGetTime();
    }

}
