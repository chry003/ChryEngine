#include "pch.hpp"
#include "Log.hpp"

namespace Chry
{
    Ref<spdlog::logger> Log::sCoreLogger;
    Ref<spdlog::logger> Log::sClientLogger;

	void Log::Init() 
	{
		spdlog::set_pattern("%^[%T] %n %v%$");
		sCoreLogger = spdlog::stdout_color_mt("<Chry>");
		sCoreLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt("<App>");
		sClientLogger->set_level(spdlog::level::trace);
	}
}
