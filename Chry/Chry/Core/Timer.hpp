#pragma once

namespace Chry
{

    class Timer
    {
        public:
            void TimerInit();
            void Tick();

            static Timer& GetInstanceOf()
            {
                static Timer ref;
                return ref;
            }

            inline float DeltaTime() { return mDeltaTime; }
            inline float GetSeconds() const { return mDeltaTime; }
            inline float GetMilliseconds() const { return mDeltaTime * 1000.0f; }

        private:
            float mLastFrame, mDeltaTime;
    };

    static Timer& timer = Timer::GetInstanceOf();

}
