#include "OpenGLSwapchainFramebuffer.h"

namespace Felix
{
   
    OpenGLSwapchainFramebuffer::OpenGLSwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc, const FramebufferCreateDesc& framebufferDesc, Window* pOwnerWindow) : SwapchainFramebuffer(swapchainDesc,framebufferDesc,pOwnerWindow)
    {

    }
    OpenGLSwapchainFramebuffer::~OpenGLSwapchainFramebuffer()
    {

    }
    void OpenGLSwapchainFramebuffer::OnResizeCore(const unsigned int width, const unsigned int Height)
    {

    }
}