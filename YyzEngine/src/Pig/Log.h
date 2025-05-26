#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
namespace Pig {
	class PIG_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define PIG_CORE_ERROR(...) ::Pig::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PIG_CORE_WARN(...) ::Pig::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PIG_CORE_INFO(...) ::Pig::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PIG_CORE_TRACE(...) ::Pig::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PIG_CORE_FATAL(...) ::Pig::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define PIG_ERROR(...) ::Pig::Log::GetClientLogger()->error(__VA_ARGS__)
#define PIG_WARN(...) ::Pig::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PIG_INFO(...) ::Pig::Log::GetClientLogger()->info(__VA_ARGS__)
#define PIG_TRACE(...) ::Pig::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PIG_FATAL(...) ::Pig::Log::GetClientLogger()->fatal(__VA_ARGS__)