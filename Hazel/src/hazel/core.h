#pragma once

#ifdef _WIN32
	#ifdef HAZEL_BUILD_DLL
//如果是Windows平台并且是Hazel库的构建，那么就导出
		#define HAZEL_API __declspec(dllexport)
	#else
//否则就导入
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
  	#error Hazel only supports Windows!
#endif
