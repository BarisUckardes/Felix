#pragma once
#include <stdio.h>

#ifdef FELIX_OS_WINDOWS
#include <Platform/Windows/Assert/WindowsAssert.h>
#else
#define ASSERT_IMPL
#endif

#define FORCEINLINE __forceinline
#define EXPORT __declspec(dllexport)


#ifdef FELIX_DEBUG
#define LOG(title,message,...) printf("[%s]: ",title); printf(message,__VA_ARGS__); printf("\n");
#else
#define LOG(title,message,...)
#endif
#define ASSERT(expression,title,message,...) if (!(expression)) { LOG(title, message, __VA_ARGS__) ASSERT_IMPL; }
