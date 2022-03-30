#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace CryingEngine {

	class ENGINE_API Log
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

// Core log macros
#define CE_CORE_TRACE(...)    ::CryingEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)     ::CryingEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)     ::CryingEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)    ::CryingEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CE_CORE_FATAL(...)    ::CryingEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CE_TRACE(...)	      ::CryingEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CE_INFO(...)	      ::CryingEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CE_WARN(...)	      ::CryingEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CE_ERROR(...)	      ::CryingEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CE_FATAL(...)	      ::CryingEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

