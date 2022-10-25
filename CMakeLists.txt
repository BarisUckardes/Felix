# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Felix")
project ("Sample")
project ("OpenGL")
project ("OpenGLES")
project ("GLX")
project ("Stbi")

# Include sub-projects.
add_subdirectory ("Felix")
add_subdirectory("Sample")
add_subdirectory("ThirdParty/OpenGL")
add_subdirectory("ThirdParty/OpenGLES")
add_subdirectory("ThirdParty/GLX")
add_subdirectory("ThirdParty/Stbi")
