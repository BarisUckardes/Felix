# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


project ("OpenGL")
project ("OpenGLES")
project ("OpenGLX")
project ("Stbi")
project ("Sample")
project ("Felix")

# Include sub-projects.
add_subdirectory("ThirdParty/OpenGL")
add_subdirectory("ThirdParty/OpenGLES")
add_subdirectory("ThirdParty/OpenGLX")
add_subdirectory("ThirdParty/Stbi")
add_subdirectory ("Felix")
add_subdirectory ("Sample")
