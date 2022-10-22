cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Sample "main.cpp")

#compiler
if (WIN32)
  add_compile_definitions(FELIX_OS_WINDOWS)
elseif(UNIX)
  add_compile_definitions(FELIX_OS_LINUX)
endif()

if(MSVC)
  add_compile_definitions(FELIX_COMPILER_MSVC)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_definitions(FELIX_COMPILER_CLANG)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_definitions(FELIX_COMPILER_GNU)
endif()

#include
include_directories(${CMAKE_SOURCE_DIR}/Felix/src)

#link
target_link_libraries(Sample PUBLIC Felix)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Felix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
