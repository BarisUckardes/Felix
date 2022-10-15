# CMakeList.txt : CMake project for Felix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (Felix "Felix.cpp" "Felix.h" "src/Window/Window.h" "src/Core/Core.h" "src/Window/WindowCreateDesc.h" "src/Window/Window.cpp" "src/Platform/Windows/Window/WindowsWindow.h" "src/Platform/Windows/Window/WindowsWindow.cpp" "src/Window/WindowEventType.h" "src/Window/WindowEvent.h" "src/Window/Events/Window/WindowClosedEvent.h" "src/Window/WindowEvents.h" "src/Window/Events/Window/WindowMovedEvent.h" "src/Window/Events/Window/WindowResizedEvent.h" "src/Platform/PlatformType.h" "src/Graphics/GraphicsAPI.h")


if (WIN32)
add_compile_definitions(FELIX_OS_WINDOWS)
endif()

include_directories("src")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Felix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
