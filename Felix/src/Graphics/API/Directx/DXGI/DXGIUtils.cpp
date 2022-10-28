#include "DXGIUtils.h"

namespace Felix
{
    DXGI_FORMAT DXGIUtils::GetFormat(const TextureFormat format)
    {
        switch (format)
        {
        case TextureFormat::None:
            return DXGI_FORMAT_UNKNOWN;
        case TextureFormat::RGB8:
            return DXGI_FORMAT_R8G8B8A8_UNORM;
        case TextureFormat::RGBA8:
            return DXGI_FORMAT_R8G8B8A8_UNORM;
        case TextureFormat::Depth24Stencil8:
            return DXGI_FORMAT_D24_UNORM_S8_UINT;
        default:
            ASSERT(false, "DX11TextureUtils", "Invalid TextureFormat");
            break;
        }
    }
}