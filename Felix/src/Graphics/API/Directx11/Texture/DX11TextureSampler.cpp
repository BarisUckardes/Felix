//
// Created by Baris on 10/28/2022.
//

#include "DX11TextureSampler.h"
#include <Graphics/API/Directx11/Texture/DX11TextureUtils.h>
#include <Graphics/API/Directx11/Device/DX11Device.h>

namespace Felix
{

    DX11TextureSampler::DX11TextureSampler(const TextureSamplerCreateDesc &desc, DX11Device *pDevice) : TextureSampler(desc)
    {
        ID3D11Device* pDX11Device = pDevice->GetDXDevice();
        D3D11_SAMPLER_DESC samplerDesc = {};
        samplerDesc.MaxAnisotropy = desc.MaxAnisotropy;
        samplerDesc.MinLOD = desc.MinLod;
        samplerDesc.MaxLOD = desc.MaxLod;
        samplerDesc.MipLODBias = desc.LodBias;
        samplerDesc.Filter = DX11TextureUtils::GetFiltering(desc.Filter,desc.bMipmaps);
        samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
        samplerDesc.AddressU = DX11TextureUtils::GetUVMode(desc.WrappingU);
        samplerDesc.AddressV = DX11TextureUtils::GetUVMode(desc.WrappingV);
        samplerDesc.AddressW = DX11TextureUtils::GetUVMode(desc.WrappingW);

        pDX11Device->CreateSamplerState(&samplerDesc,&_sampler);
    }

    DX11TextureSampler::~DX11TextureSampler()
    {

    }
}