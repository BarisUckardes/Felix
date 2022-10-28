//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11TEXTURE_H
#define STBI_DX11TEXTURE_H

#include <Graphics/API/Directx11/Core/DX11Core.h>
#include <Graphics/Texture/Texture.h>
#include <d3d11.h>

namespace Felix
{
    class DX11Device;
    class EXPORT DX11Texture : public Texture {
    public:
        DX11Texture(const TextureCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11Texture() override;

        FORCEINLINE ID3D11Texture1D* GetDXTexture1D() const noexcept { return _texture1D.Get();}
        FORCEINLINE ID3D11Texture2D* GetDXTexture2D() const noexcept { return _texture2D.Get();}
        FORCEINLINE ID3D11Texture3D* GetDXTexture3D() const noexcept { return _texture3D.Get();}
    private:
        void _CreateAs1D(const TextureCreateDesc& desc,DX11Device* pDevice);
        void _CreateAs2D(const TextureCreateDesc& desc,DX11Device* pDevice);
        void _CreateAs3D(const TextureCreateDesc& desc,DX11Device* pDevice);
    private:
        DXPTR<ID3D11Texture1D> _texture1D;
        DXPTR<ID3D11Texture2D> _texture2D;
        DXPTR<ID3D11Texture3D> _texture3D;
    };


}
#endif //STBI_DX11TEXTURE_H
