//
// Created by Baris on 10/28/2022.
//

#ifndef FELIX_DX11TEXTURESAMPLER_H
#define FELIX_DX11TEXTURESAMPLER_H


#include <Graphics/Texture/TextureSampler.h>
#include <Graphics/API/Directx11/Core/DX11Core.h>

#include <d3d11.h>

namespace Felix
{
    class EXPORT DX11TextureSampler : public TextureSampler {
    public:
        DX11TextureSampler(const TextureSamplerCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11TextureSampler() override;

        FORCEINLINE ID3D11SamplerState* GetDX11Sampler() const noexcept { return _sampler.Get();}
    private:
        DXPTR<ID3D11SamplerState> _sampler;
    };

}

#endif //FELIX_DX11TEXTURESAMPLER_H
