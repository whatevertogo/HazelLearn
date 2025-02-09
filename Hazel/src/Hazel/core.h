#pragma once


	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
#else
	#error Hazel only supports Windows!
#endif

