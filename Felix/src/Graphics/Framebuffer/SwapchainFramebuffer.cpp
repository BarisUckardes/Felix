#include "SwapchainFramebuffer.h"

namespace Felix
{
    void SwapchainFramebuffer::OnResize(const unsigned int width, const unsigned int height)
    {
        OnResizeCore(width, height);
        _SetWidth(width);
        _SetHeight(height);
    }
}