cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (WindowsTest "main.cpp")

#include
include_directories(${CMAKE_SOURCE_DIR}/Felix/src)

#link
target_link_libraries(WindowsTest PUBLIC Felix)

if (WIN32)
add_compile_definitions(FELIX_OS_WINDOWS)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Felix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
