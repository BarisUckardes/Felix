#pragma once
#include <stdio.h>

#ifdef FELIX_OS_WINDOWS
#include <Platform/Windows/Assert/WindowsAssert.h>
#define EXPORT __declspec(dllexport)
#elif FELIX_OS_LINUX
#include <Platform/Linux/Assert/LinuxAssert.h>
#define EXPORT
#endif

#ifdef FELIX_COMPILER_MSVC
#define FORCEINLINE __forceinline
#elif FELIX_COMPILER_CLANG
#define FORCEINLINE
#elif FELIX_COMPILER_GNU
#define FORCEINLINE
#endif

#ifdef FELIX_DEBUG
#define LOG(title,message,...) printf("[%s]:",title); printf(message,__VA_ARGS__); printf("\n"); fflush(stdout);
#else
#define LOG(title,message,...) printf("[%s]:",title); printf(message,__VA_ARGS__); printf("\n"); fflush(stdout);
#endif

#ifdef FELIX_SAFE
#define ASSERT(expression,title,message,...) if(!(expression)) { LOG(title,message,__VA_ARGS__) ASSERT_IMPL(expression)  }
#else
#define ASSERT(expression,title,message,...)
#endif

