//
// Created by Baris on 10/26/2022.
//

#include "DX11TextureUtils.h"


namespace Felix
{

    D3D11_USAGE DX11TextureUtils::GetUsage(const TextureUsage usage)
    {
        if (usage & TextureUsage::DepthStencilTarget || usage & TextureUsage::RenderTarget || usage & TextureUsage::Sampled )
        {
            return D3D11_USAGE_DEFAULT;
        }
    }

    unsigned int DX11TextureUtils::GetBindFlags(const TextureUsage usage)
    {
        unsigned int flags = 0;

        if(usage & TextureUsage::Sampled)
        {
            flags|=D3D11_BIND_SHADER_RESOURCE;
        }
        if(usage & TextureUsage::RenderTarget)
        {
            flags|=D3D11_BIND_RENDER_TARGET;
        }
        if(usage & TextureUsage::DepthStencilTarget)
        {
            flags |= D3D11_BIND_DEPTH_STENCIL;
        }

        return flags;
    }

    DXGI_FORMAT DX11TextureUtils::GetFormat(const TextureFormat format)
    {
        switch(format)
        {
            case TextureFormat::None:
                return DXGI_FORMAT_UNKNOWN;
            case TextureFormat::RGB8:
                return DXGI_FORMAT_R8G8B8A8_UINT;
            case TextureFormat::RGBA8:
                return DXGI_FORMAT_R8G8B8A8_UINT;
            case TextureFormat::Depth24Stencil8:
                return DXGI_FORMAT_D24_UNORM_S8_UINT;
            default:
                ASSERT(false,"DX11TextureUtils","Invalid TextureFormat");
                break;
        }
    }

    D3D11_SRV_DIMENSION DX11TextureUtils::GetDimension(const TextureType type)
    {
        switch (type)
        {
            case TextureType::Texture1D:
                return D3D11_SRV_DIMENSION_TEXTURE1D;
            case TextureType::Texture2D:
                return D3D11_SRV_DIMENSION_TEXTURE2D;
            case TextureType::Texture3D:
                return D3D11_SRV_DIMENSION_TEXTURE3D;
            case TextureType::CubeTexture:
                return D3D11_SRV_DIMENSION_TEXTURECUBE;
            default:
                ASSERT(false,"DX11TextureUtils","Invalid TextureType");
                break;
        }
    }

    unsigned int DX11TextureUtils::GetCPUAccessFlags(const TextureUsage usage)
    {
        return 0;
    }

    D3D11_TEXTURE_ADDRESS_MODE DX11TextureUtils::GetUVMode(const TextureSamplerWrapMode mode)
    {
        switch (mode)
        {
            case TextureSamplerWrapMode::ClampToEdge:
                return D3D11_TEXTURE_ADDRESS_CLAMP;
            case TextureSamplerWrapMode::MirroredRepeat:
                return D3D11_TEXTURE_ADDRESS_MIRROR;
            case TextureSamplerWrapMode::Repeat:
                return D3D11_TEXTURE_ADDRESS_MIRROR;
            default:
                ASSERT(false,"DX11TextureUtils","Invalid TextureSamplerWrapMode!");

        }
    }

    D3D11_FILTER DX11TextureUtils::GetFiltering(const TextureSamplerFilter filter,const bool bMipmaps)
    {
        return D3D11_FILTER_ANISOTROPIC;
    }
}