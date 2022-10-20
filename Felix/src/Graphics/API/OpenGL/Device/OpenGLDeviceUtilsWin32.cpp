#include "OpenGLDeviceUtilsWin32.h"

namespace Felix
{
    unsigned int OpenGLDeviceUtilsWin32::GetColorBits(const TextureFormat format) noexcept
    {
        switch (format)
        {
            case Felix::TextureFormat::None:
                return 0;
            case Felix::TextureFormat::RGB8:
            case Felix::TextureFormat::RGBA8:
                return 8;
            case Felix::TextureFormat::Depth24Stencil8:
                return 0;
            default:
                ASSERT(false, "OpenGLDeviceUtilsWin32", "Invalid TextureFormat!");
                break;
        }
    }
    unsigned int OpenGLDeviceUtilsWin32::GetAlphaBits(const TextureFormat format) noexcept
    {
        switch (format)
        {
        case Felix::TextureFormat::None:
            return 0;
        case Felix::TextureFormat::RGB8:
        case Felix::TextureFormat::RGBA8:
            return 8;
        case Felix::TextureFormat::Depth24Stencil8:
            return 0;
        default:
            ASSERT(false, "OpenGLDeviceUtilsWin32", "Invalid TextureFormat!");
            break;
        }
    }
    unsigned int OpenGLDeviceUtilsWin32::GetDepthBits(const TextureFormat format) noexcept
    {
        switch (format)
        {
            case Felix::TextureFormat::None:
            case Felix::TextureFormat::RGB8:
            case Felix::TextureFormat::RGBA8:
                return 0;
            case Felix::TextureFormat::Depth24Stencil8:
                return 24;
            default:
                ASSERT(false, "OpenGLDeviceUtilsWin32", "Invalid TextureFormat!");
                break;
        }
    }
    unsigned int OpenGLDeviceUtilsWin32::GetStencilBits(const TextureFormat format) noexcept
    {
        switch (format)
        {
            case Felix::TextureFormat::None:
            case Felix::TextureFormat::RGB8:
            case Felix::TextureFormat::RGBA8:
                return 8;
            case Felix::TextureFormat::Depth24Stencil8:
                return 8;
            default:
                ASSERT(false, "OpenGLDeviceUtilsWin32", "Invalid TextureFormat!");
                break;
        }
    }
}