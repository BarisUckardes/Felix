#pragma once
#include <stdio.h>

#ifdef FELIX_OS_WINDOWS
#include <Platform/Windows/Assert/WindowsAssert.h>
#define EXPORT __declspec(dllexport)
<<<<<<< Updated upstream
#else
#define ASSERT_IMPL
=======
#elif FELIX_OS_LINUX
>>>>>>> Stashed changes
#define EXPORT
#endif

#ifdef FELIX_COMPILER_MSVC
<<<<<<< Updated upstream
#define FORCEINLINE __forceinline
#elif FELIX_COMPILER_CLANG
#define FORCEINLINE
#else 
#define FORCEINLINE
#endif

=======
#define  FORCEINLINE __forceinline
#elif FELIX_COMPILER_GNU
#define FORCEINLINE
#endif
>>>>>>> Stashed changes


#ifdef FELIX_DEBUG
#define LOG(title,message,...)
#else
#define LOG(title,message,...)
#endif
#define ASSERT(expression,title,message,...)
