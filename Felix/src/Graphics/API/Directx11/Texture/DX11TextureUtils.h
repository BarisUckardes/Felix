//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11TEXTUREUTILS_H
#define STBI_DX11TEXTUREUTILS_H

#include <Graphics/API/Directx11/Core/DX11Core.h>
#include <Core/Core.h>
#include <Graphics/Texture/TextureFormat.h>
#include <Graphics/Texture/TextureUsage.h>
#include <Graphics/Texture/TextureType.h>
#include <Graphics/Texture/TextureSamplerWrapMode.h>
#include <Graphics/Texture/TextureSamplerFilter.h>
#include <d3d11.h>

namespace Felix
{
    class EXPORT DX11TextureUtils {
    public:
        DX11TextureUtils() = delete;
        ~DX11TextureUtils() = delete;

        FORCEINLINE static D3D11_USAGE GetUsage(const TextureUsage usage);
        FORCEINLINE static unsigned int GetBindFlags(const TextureUsage usage);
        FORCEINLINE static D3D11_SRV_DIMENSION  GetDimension(const TextureType type);
        FORCEINLINE static unsigned int GetCPUAccessFlags(const TextureUsage usage);
        FORCEINLINE static D3D11_TEXTURE_ADDRESS_MODE GetUVMode(const TextureSamplerWrapMode mode);
        FORCEINLINE static D3D11_FILTER GetFiltering(const TextureSamplerFilter filte,const bool bMipmaps);
    };

}

#endif //STBI_DX11TEXTUREUTILS_H
