#pragma once
#include <stdio.h>

#ifdef FELIX_OS_WINDOWS
#include <Platform/Windows/Assert/WindowsAssert.h>
#define EXPORT __declspec(dllexport)
#else
#define ASSERT_IMPL
#define EXPORT
#endif

#ifdef FELIX_COMPILER_MSVC
#define FORCEINLINE __forceinline
#elif FELIX_COMPILER_CLANG
#define FORCEINLINE
#else 
#define FORCEINLINE
#endif



#ifdef FELIX_DEBUG
#define LOG(title,message,...) printf("[%s]: ",title); printf(message,__VA_ARGS__); printf("\n");
#else
#define LOG(title,message,...)
#endif
#define ASSERT(expression,title,message,...) if (!(expression)) { LOG(title, message, __VA_ARGS__) ASSERT_IMPL; }
