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
#define LOG(title,message,...)
#else
#define LOG(title,message,...)
#endif
#define ASSERT(expression,title,message,...) ASSERT_IMPL(expression)
