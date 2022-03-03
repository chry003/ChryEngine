#pragma once

#include "Base.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Chry
{

    class Log
    {
        public:
            static void Init();

            inline static Ref<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
            inline static Ref<spdlog::logger>& GetClientLogger() { return sClientLogger; }

        private:
            static Ref<spdlog::logger> sCoreLogger;
            static Ref<spdlog::logger> sClientLogger;
    };

}

#define CORE_LOG_TRACE(...)     ::Chry::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_LOG_INFO(...)     ::Chry::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_LOG_WARN(...)     ::Chry::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG_ERROR(...)     ::Chry::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_LOG_FATAL(...)     ::Chry::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define CLIENT_LOG_TRACE(...)     ::Chry::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_LOG_INFO(...)     ::Chry::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_LOG_WARN(...)     ::Chry::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_LOG_ERROR(...)     ::Chry::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_LOG_FATAL(...)     ::Chry::Log::GetClientLogger()->fatal(__VA_ARGS__)
