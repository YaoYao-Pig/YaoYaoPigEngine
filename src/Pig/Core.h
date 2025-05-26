#pragma once
  
#ifdef PIG_PLATFORM_WIN
	#ifdef PIG_BUILD_DLL
		#define PIG_API __declspec(dllexport)
	#else
		#define PIG_API __declspec(dllimport)
	#endif
#else
	#error Pig only support win!
#endif