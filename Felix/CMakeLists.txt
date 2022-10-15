﻿# CMakeList.txt : CMake project for Felix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (Felix "Felix.cpp" "Felix.h" "src/Window/Window.h" "src/Core/Core.h" "src/Window/WindowCreateDesc.h" "src/Window/Window.cpp" "src/Platform/Windows/Window/WindowsWindow.h" "src/Platform/Windows/Window/WindowsWindow.cpp" "src/Window/WindowEventType.h" "src/Window/WindowEvent.h" "src/Window/Events/Window/WindowClosedEvent.h" "src/Window/WindowEvents.h" "src/Window/Events/Window/WindowMovedEvent.h" "src/Window/Events/Window/WindowResizedEvent.h" "src/Platform/PlatformType.h" "src/Graphics/GraphicsAPI.h" "src/Graphics/Device/GraphicsDevice.h" "src/Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h" "src/Graphics/Device/WindowGraphicsDeviceCreateDesc.h" "src/Graphics/Texture/TextureFormat.h" "src/Graphics/Device/GraphicsDeviceCapabilities.h" "src/Platform/Windows/Assert/WindowsAssert.h" "src/Graphics/Device/GraphicsDevice.cpp" "src/Graphics/API/OpenGL/Device/OpenGLDevice.h" "src/Graphics/API/OpenGL/Device/OpenGLDevice.cpp")


#compiler flags
if (WIN32)
add_compile_definitions(FELIX_OS_WINDOWS)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
add_compile_definitions(FELIX_DEBUG)
endif()

#include
include_directories("src")
include_directories("ThirdParty/OpenGL/GLAD/include")

#linker
link_directories("ThirdParty/OpenGL/WGL/lib")

target_link_libraries(Felix OpenGL)
target_link_libraries(Felix OpenGL32.lib)



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Felix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.