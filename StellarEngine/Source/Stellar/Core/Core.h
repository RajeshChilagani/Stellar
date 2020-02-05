#pragma once
#ifdef STLR_PLATFORM_WINDOWS
	#ifdef STLR_BUILD_DLL
		#define STELLAR_API __declspec(dllexport)
	#else
		#define STELLAR_API __declspec(dllimport)
	#endif
#else
	#error Platform is not currently supported by STELLAR
#endif
