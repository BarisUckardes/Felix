#ifdef FELIX_OS_WINDOWS
//
// Created by Baris on 10/26/2022.
//

#include "DX11TextureUtils.h"


namespace Felix
{

    D3D11_USAGE DX11TextureUtils::GetUsage(const TextureUsage usage)
    {
        if (usage & TextureUsage::Sampled)
        {
            return D3D11_USAGE_IMMUTABLE;
        }
        if(usage & TextureUsage::RenderTarget)
        {
            return D3D11_USAGE_IMMUTABLE;
        }
        if(usage & TextureUsage::DepthStencilTarget)
        {
            return D3D11_USAGE_IMMUTABLE;
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
        switch (filter)
        {
            case TextureSamplerFilter::Anisotropic:
                return D3D11_FILTER_ANISOTROPIC;
            case TextureSamplerFilter::MinPointMagPointMipPoint:
                return D3D11_FILTER_MIN_MAG_MIP_POINT;
            case TextureSamplerFilter::MinPointMagPointMipLinear:
                return D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR;
            case TextureSamplerFilter::MinPointMagLinearMipPoint:
                return D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT;
            case TextureSamplerFilter::MinPointMagLinearMipLinear:
                return D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR;
            case TextureSamplerFilter::MinLinearMagPointMipPoint:
                return D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT;
            case TextureSamplerFilter::MinLinearMagPointMipLinear:
                return D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
            case TextureSamplerFilter::MinLinearMagLinearMipPoint:
                return D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
            case TextureSamplerFilter::MinLinearMagLinearMipLinear:
                return D3D11_FILTER_MIN_MAG_MIP_LINEAR;
            default:
                ASSERT(false,"OpenGLTextureSamplerUtils","Invalid TextureSamplerFilter!");
        }
    }
}
#endif