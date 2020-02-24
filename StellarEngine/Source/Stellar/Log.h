#pragma once
#include "Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Stellar
{
	class STELLAR_API Log
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

//Core Logger Macros
#define STLR_CORE_TRACE(...)         ::Stellar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define STLR_CORE_INFO(...)          ::Stellar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define STLR_CORE_WARN(...)          ::Stellar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define STLR_CORE_ERROR(...)         ::Stellar::Log::GetCoreLogger()->error(__VA_ARGS__)
									 
//Client Logger Macros				 
#define STLR_TRACE(...)              ::Stellar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define STLR_INFO(...)               ::Stellar::Log::GetClientLogger()->info(__VA_ARGS__)
#define STLR_WARN(...)               ::Stellar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define STLR_ERROR(...)              ::Stellar::Log::GetClientLogger()->error(__VA_ARGS__);
