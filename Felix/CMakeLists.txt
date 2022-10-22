# CMakeList.txt : CMake project for Felix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (Felix "Felix.cpp" "Felix.h" "src/Window/Window.h" "src/Core/Core.h" "src/Window/WindowCreateDesc.h" "src/Window/Window.cpp" "src/Platform/Windows/Window/WindowsWindow.h" "src/Platform/Windows/Window/WindowsWindow.cpp" "src/Window/WindowEventType.h" "src/Window/WindowEvent.h" "src/Window/Events/Window/WindowClosedEvent.h" "src/Window/WindowEvents.h" "src/Window/Events/Window/WindowMovedEvent.h" "src/Window/Events/Window/WindowResizedEvent.h" "src/Platform/PlatformType.h" "src/Graphics/GraphicsAPI.h" "src/Graphics/Device/GraphicsDevice.h" "src/Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h" "src/Graphics/Device/WindowGraphicsDeviceCreateDesc.h" "src/Graphics/Texture/TextureFormat.h" "src/Graphics/Device/GraphicsDeviceCapabilities.h" "src/Platform/Windows/Assert/WindowsAssert.h" "src/Graphics/Device/GraphicsDevice.cpp" "src/Graphics/API/OpenGL/Device/OpenGLDevice.h" "src/Graphics/API/OpenGL/Device/OpenGLDevice.cpp" "src/Graphics/Device/GraphicsDeviceObjectType.h" "src/Graphics/Device/GraphicsDeviceObject.h" "src/Graphics/Command/CommandBuffer.h" "src/Graphics/Command/CommandBufferCreateDesc.h" "src/Graphics/API/OpenGL/Command/OpenGLCommandBuffer.h" "src/Graphics/API/OpenGL/Command/OpenGLCommandBuffer.cpp" "src/Graphics/Device/GraphicsDeviceObjects.h" "src/Graphics/API/OpenGL/Device/OpenGLDeviceObjects.h" "src/Graphics/Command/CommandBuffer.cpp" "src/Graphics/Buffer/GraphicsBuffer.h" "src/Graphics/Buffer/GraphicsBufferType.h" "src/Graphics/Buffer/GraphicsBufferUsage.h" "src/Graphics/Buffer/GraphicsBufferCreateDesc.h" "src/Graphics/API/OpenGL/Buffer/OpenGLBuffer.h" "src/Graphics/API/OpenGL/Buffer/OpenGLBuffer.cpp" "src/Graphics/API/OpenGL/Buffer/OpenGLBufferUtils.h" "src/Graphics/API/OpenGL/Buffer/OpenGLBufferUtils.cpp" "src/Graphics/Texture/TextureType.h" "src/Graphics/Texture/TextureUsage.h" "src/Graphics/Texture/TextureCreateDesc.h" "src/Graphics/Buffer/GraphicsBufferUpdateDesc.h" "src/Graphics/Texture/Texture.h" "src/Graphics/API/OpenGL/Texture/OpenGLTextureUtils.h" "src/Graphics/API/OpenGL/Texture/OpenGLTextureUtils.cpp" "src/Graphics/API/OpenGL/Texture/OpenGLTexture.h" "src/Graphics/API/OpenGL/Texture/OpenGLTexture.cpp" "src/Graphics/Texture/TextureUpdateDesc.h" "src/Graphics/Framebuffer/FramebufferCreateDesc.h" "src/Graphics/Framebuffer/FramebufferAttachmentDesc.h" "src/Graphics/Framebuffer/Framebuffer.h" "src/Graphics/Framebuffer/Framebuffer.cpp" "src/Graphics/Framebuffer/SwapchainFramebufferCreateDesc.h" "src/Graphics/Framebuffer/SwapchainFramebuffer.h" "src/Window/WindowDeviceAdapter.h" "src/Window/WindowDeviceAdapter.cpp" "src/Graphics/Framebuffer/SwapchainFramebuffer.cpp" "src/Graphics/API/OpenGL/Framebuffer/OpenGLFramebuffer.h" "src/Graphics/API/OpenGL/Framebuffer/OpenGLFramebuffer.cpp" "src/Graphics/API/OpenGL/Framebuffer/OpenGLSwapchainFramebuffer.h" "src/Graphics/API/OpenGL/Framebuffer/OpenGLSwapchainFramebuffer.cpp" "src/Graphics/API/OpenGL/Framebuffer/OpenGLFramebufferUtils.h" "src/Graphics/Shader/ShaderType.h" "src/Graphics/Shader/ShaderCreateDesc.h" "src/Graphics/Shader/Shader.h" "src/Graphics/API/OpenGL/Shader/OpenGLShaderUtils.h" "src/Graphics/API/OpenGL/Shader/OpenGLShaderUtils.cpp" "src/Graphics/API/OpenGL/Shader/OpenGLShader.h" "src/Graphics/API/OpenGL/Shader/OpenGLShader.cpp" "src/Graphics/Resource/GraphicsResourceType.h" "src/Graphics/Resource/GraphicsResourceCreateDesc.h" "src/Graphics/Resource/GraphicsResource.h" "src/Graphics/API/OpenGL/Resource/OpenGLGraphicsResource.h" "src/Graphics/Pipeline/ViewportDesc.h" "src/Graphics/Pipeline/ScissorsDesc.h" "src/Graphics/Pipeline/InputElementDesc.h" "src/Graphics/Pipeline/InputElementDataType.h" "src/Graphics/Pipeline/InputLayoutDesc.h" "src/Graphics/Pipeline/InputElementUtils.h" "src/Graphics/Pipeline/InputElementUtils.cpp" "src/Graphics/Pipeline/InputLayoutDesc.cpp" "src/Graphics/Pipeline/CullMode.h" "src/Graphics/Pipeline/FrontFaceMode.h" "src/Graphics/Pipeline/PolygonShadingMode.h" "src/Graphics/Pipeline/PrimitiveTopology.h" "src/Graphics/Pipeline/RasterizerStateDesc.h" "src/Graphics/Pipeline/DepthStencilStateDesc.h" "src/Graphics/Pipeline/DepthTestFunction.h" "src/Graphics/Pipeline/StencilFunction.h" "src/Graphics/Pipeline/StencilOperation.h" "src/Graphics/Pipeline/StencilFaceDesc.h" "src/Graphics/Pipeline/OutputDesc.h" "src/Graphics/Pipeline/ResourceSlotDesc.h" "src/Graphics/Pipeline/ResourceStateDesc.h" "src/Graphics/Pipeline/ShaderPassDesc.h" "src/Graphics/Pipeline/PipelineCreateDesc.h" "src/Graphics/Pipeline/BlendingFactor.h" "src/Graphics/Pipeline/BlendingFunction.h" "src/Graphics/Pipeline/BlendingStateDesc.h"  "src/Graphics/Pipeline/PipelineType.h" "src/Graphics/Pipeline/Pipeline.h" "src/Graphics/API/OpenGL/Pipeline/OpenGLPipeline.h" "src/Graphics/API/OpenGL/Pipeline/OpenGLPipeline.cpp" "src/Graphics/API/OpenGL/Pipeline/OpenGLPipelineUtils.h" "src/Graphics/API/OpenGL/Pipeline/OpenGLPipelineUtils.cpp" "src/Graphics/API/OpenGL/Device/OpenGLDeviceUtilsWin32.h" "src/Graphics/API/OpenGL/Device/OpenGLDeviceUtilsWin32.cpp" "src/Graphics/Texture/TextureSampler.h"  "src/Graphics/Texture/TextureSamplerMinFilter.h" "src/Graphics/Texture/TextureSamplerMagFilter.h" "src/Graphics/Texture/TextureSamplerWrapMode.h" "src/Graphics/Texture/TextureSamplerCreateDesc.h" "src/Graphics/API/OpenGL/Texture/OpenGLTextureSampler.h" "src/Graphics/API/OpenGL/Texture/OpenGLTextureSampler.cpp" "src/Graphics/API/OpenGL/Texture/OpenGLTextureSamplerUtils.h"  "src/Graphics/API/OpenGL/Resource/OpenGLTextureSamplerResource.h" "src/Graphics/API/OpenGL/Resource/OpenGLConstantBufferResource.h" "src/Graphics/API/OpenGL/Resource/OpenGLConstantBufferResource.cpp" "src/Graphics/Texture/TextureLoadResult.h" "src/Graphics/Texture/TextureLoader.h" "src/Graphics/Texture/TextureLoader.cpp" "src/Graphics/Texture/TextureLoaderUtils.h" "src/Graphics/Texture/TextureLoaderUtils.cpp" "src/Graphics/API/OpenGL/Resource/OpenGLTextureResource.h" "src/Graphics/API/OpenGL/Resource/OpenGLTextureResource.cpp" "src/Graphics/API/OpenGL/Texture/OpenGlTextureSamplerUtils.cpp")

#compiler flags
if (WIN32)
<<<<<<< Updated upstream
add_compile_definitions(FELIX_OS_WINDOWS)
elseif(LINUX)
add_compile_definitions(FELIX_OS_LINUX)
=======
  add_compile_definitions(FELIX_OS_WINDOWS)
elseif(UNIX)
  add_compile_definitions(FELIX_OS_LINUX)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  add_compile_definitions(FELIX_COMPILER_MSVC)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_definitions(FELIX_COMPILER_CLANG)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_definitions(FELIX_COMPILER_GNU)
>>>>>>> Stashed changes
endif()


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
add_compile_definitions(FELIX_DEBUG)
endif()

if(MSVC)
add_compile_definitions(FELIX_COMPILER_MSVC)
else()
add_compile_definitions(FELIX_COMPILER_CLANG)
endif()

#include
include_directories("src")
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/OpenGL/include)
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/Stbi/include)

#linker
link_directories(${CMAKE_SOURCE_DIR}/ThirdParty/WGL/lib)

target_link_libraries(Felix Stbi)
target_link_libraries(Felix OpenGL)

if(WIN32)
  target_link_libraries(Felix OpenGL32.lib)
endif()



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Felix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
