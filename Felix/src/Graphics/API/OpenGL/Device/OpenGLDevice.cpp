#include "OpenGLDevice.h"
#include <GLAD/glad.h>
#include <Graphics/API/OpenGL/Device/OpenGLDeviceObjects.h>
#include <Graphics/Buffer/GraphicsBufferUpdateDesc.h>
#include <Graphics/Texture/TextureUpdateDesc.h>
#include <Graphics/API/OpenGL/Buffer/OpenGLBufferUtils.h>
#include <Graphics/API/OpenGL/Texture/OpenGLTextureUtils.h>

#ifdef FELIX_OS_WINDOWS
#include <Platform/Windows/Window/WindowsWindow.h>
#include <Graphics/API/OpenGL/Device/OpenGLDeviceUtilsWin32.h>
typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
typedef const char* (WINAPI* PFNWGLGETEXTENSIONSSTRINGEXTPROC)(void);
typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC)(int);
typedef int (WINAPI* PFNWGLGETSWAPINTERVALEXTPROC) (void);
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0X2092
#define WGL_CONTEXT_FLAGS_ARB 0X2094
#define WGL_CONTEXT_COREPROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#endif

namespace Felix
{
    OpenGLDevice::OpenGLDevice(const WindowGraphicsDeviceCreateDesc& desc,Window* pOwnerWindow) : GraphicsDevice(pOwnerWindow)
    {

#ifdef FELIX_OS_WINDOWS
        const WindowsWindow* pWin32Window = (const WindowsWindow*)pOwnerWindow;

        HWND windowHandle = pWin32Window->GetWin32WindowHandle();
        HDC windowDeviceContext = pWin32Window->GetWin32WindowDeviceContext();

        /*
        * Create pixel format
        */
        PIXELFORMATDESCRIPTOR pfd = { sizeof(pfd),1 };
        memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.nVersion = 1;
        pfd.cColorBits = OpenGLDeviceUtilsWin32::GetColorBits(desc.SwapchainBufferFormat);
        pfd.cAlphaBits = OpenGLDeviceUtilsWin32::GetAlphaBits(desc.SwapchainBufferFormat);
        pfd.cDepthBits = OpenGLDeviceUtilsWin32::GetDepthBits(desc.SwapchainDepthStencilBufferFormat);
        pfd.cStencilBits = OpenGLDeviceUtilsWin32::GetStencilBits(desc.SwapchainDepthStencilBufferFormat);
        pfd.cAuxBuffers = 3;
        pfd.iLayerType = PFD_MAIN_PLANE;

        const int pixelFormatIndex = ChoosePixelFormat(windowDeviceContext, &pfd);
        ASSERT(pixelFormatIndex != 0,"OpenGLDevice","Invalid pixel format");

        ASSERT(SetPixelFormat(windowDeviceContext, pixelFormatIndex, &pfd), "OpenGLDevice", "Win32 window rejected the specified pixel format");

        HGLRC tempContext = wglCreateContext(windowDeviceContext);
        ASSERT(tempContext != NULL, "OpenGLDevice", "Creation of wgl dummy context failed!");

        wglMakeCurrent(windowDeviceContext, tempContext);

        PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
        ASSERT(wglCreateContextAttribsARB != NULL, "OpenGLDevice", "WGL get proc address failed!");

        constexpr int attribList[] =
        {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 6,
            WGL_CONTEXT_FLAGS_ARB, 0,
            WGL_CONTEXT_PROFILE_MASK_ARB,
            WGL_CONTEXT_COREPROFILE_BIT_ARB,0
        };

        HGLRC gladContext = wglCreateContextAttribsARB(windowDeviceContext, NULL, attribList);

        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(tempContext);

        wglMakeCurrent(windowDeviceContext, gladContext);

        ASSERT(gladLoadGL() != 0, "OpenGLDevice", "Glad initialization failed!");

        _context = gladContext;
        _windowDeviceContext = windowDeviceContext;
#endif

#ifdef FELIX_DEBUG
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(
            [](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
            {
                LOG("OpenGL", "%s", message);
            }, nullptr);
#endif

    }
    OpenGLDevice::~OpenGLDevice()
    {

    }
    void OpenGLDevice::SwapbuffersCore()
    {
        SwapBuffers(_windowDeviceContext);
    }
    CommandBuffer* OpenGLDevice::CreateCommandBufferCore(const CommandBufferCreateDesc& desc)
    {
        return new OpenGLCommandBuffer(desc);
    }
    GraphicsBuffer* OpenGLDevice::CreateBufferCore(const GraphicsBufferCreateDesc& desc)
    {
        return new OpenGLBuffer(desc);
    }
    Shader* OpenGLDevice::CreateShaderCore(const ShaderCreateDesc& desc)
    {
        return new OpenGLShader(desc);
    }
    Texture* OpenGLDevice::CreateTextureCore(const TextureCreateDesc& desc)
    {
        return new OpenGLTexture(desc);
    }
    void OpenGLDevice::UpdateBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferUpdateDesc& desc)
    {
        const OpenGLBuffer* pGLBuffer = (const OpenGLBuffer*)pBuffer;

        glNamedBufferSubData(pGLBuffer->GetGLHandle(), desc.Offset, desc.Size, desc.pData);
    }
    void OpenGLDevice::UpdateTextureCore(Texture* pTexture, const TextureUpdateDesc& desc)
    {
        const OpenGLTexture* pGLTexture = (const OpenGLTexture*)pTexture;

        const TextureType type = pTexture->GetTextureType();
        const unsigned handle = pGLTexture->GetGLHandle();
        const unsigned int format = OpenGLTextureUtils::GetTextureFormat(pTexture->GetFormat());
        const unsigned int dataType = OpenGLTextureUtils::GetDataType(pTexture->GetFormat());

        switch (type)
        {
            case Felix::TextureType::Texture1D:
            {
                glTextureSubImage1D(
                    handle,
                    0,
                    0,
                    pTexture->GetWidth(),
                    format,
                    dataType,
                    desc.pData);
                break;
            }
            case Felix::TextureType::Texture2D:
            {
                glTextureSubImage2D(
                    handle,
                    0,
                    0,
                    0,
                    pTexture->GetWidth(),
                    pTexture->GetHeight(),
                    format,
                    dataType,
                    desc.pData
                );
                break;
            }
            case Felix::TextureType::Texture3D:
            {
                glTextureSubImage3D(
                    handle,
                    0,
                    0,
                    0,
                    0,
                    pTexture->GetWidth(),
                    pTexture->GetHeight(),
                    pTexture->GetDepth(),
                    format,
                    dataType,
                    desc.pData
                );
                break;
            }
            case Felix::TextureType::CubeTexture:
                break;
            default:
                break;
        }
    }
    TextureSampler* OpenGLDevice::CreateTextureSamplerCore(const TextureSamplerCreateDesc& desc)
    {
        return new OpenGLTextureSampler(desc);
    }
    Pipeline* OpenGLDevice::CreatePipelineCore(const PipelineCreateDesc& desc)
    {
        return new OpenGLPipeline(desc);
    }
    GraphicsResource* OpenGLDevice::CreateResourceCore(const GraphicsResourceCreateDesc& desc)
    {
        return new OpenGLGraphicsResource(desc);
    }
    Framebuffer* OpenGLDevice::CreateFramebufferCore(const FramebufferCreateDesc& desc)
    {
        return new OpenGLFramebuffer(desc,false);
    }
    Framebuffer* OpenGLDevice::CreateSwapchainFramebufferCore(const SwapchainFramebufferCreateDesc& desc)
    {
        return new OpenGLSwapchainFramebuffer(desc,{},GetOwnerWindow());
    }
}