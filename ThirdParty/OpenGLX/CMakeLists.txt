add_library(OpenGLX "include/GLAD/glx.h" "src/glx.c" )
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/OpenGLX/include)
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/OpenGL/include)