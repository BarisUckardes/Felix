//
// Created by Baris on 10/26/2022.
//

#include "DX11Texture.h"
#include <Graphics/API/Directx11/Texture/DX11TextureUtils.h>
#include <Graphics/API/Directx11/Device/DX11Device.h>

namespace Felix
{

    DX11Texture::DX11Texture(const TextureCreateDesc &desc, DX11Device *pDevice) : Texture(desc)
    {
        switch(desc.Type)
        {
            case TextureType::Texture1D:
                _CreateAs1D(desc,pDevice);
                break;
            case TextureType::Texture2D:
                _CreateAs2D(desc,pDevice);
                break;
            case TextureType::Texture3D:
                _CreateAs3D(desc,pDevice);
                break;
            case TextureType::CubeTexture:
                ASSERT(false,"DX11Texture","Cube texture not supported yet");
                break;

        }
    }
    DX11Texture::~DX11Texture()
    {

    }

    void DX11Texture::_CreateAs1D(const TextureCreateDesc &desc, DX11Device *pDevice)
    {
        D3D11_TEXTURE1D_DESC textureDesc = {};
        textureDesc.Width = desc.Width;
        textureDesc.Usage = DX11TextureUtils::GetUsage(desc.UsageFlags);
        textureDesc.BindFlags = DX11TextureUtils::GetBindFlags(desc.UsageFlags);
        textureDesc.Format = DX11TextureUtils::GetFormat(desc.Format);
        textureDesc.MipLevels = 1;
        textureDesc.MiscFlags = 0;
        textureDesc.CPUAccessFlags = DX11TextureUtils::GetCPUAccessFlags(desc.UsageFlags);
        textureDesc.ArraySize = 1;

        D3D11_SUBRESOURCE_DATA subresourceData = {};
        subresourceData.pSysMem = desc.pInitialData;
        subresourceData.SysMemPitch = 0;
        subresourceData.SysMemSlicePitch = 0;

       if(desc.pInitialData != nullptr)
       {
           ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateTexture1D(&textureDesc,&subresourceData,&_texture1D)),"DX11Texture","Texture1D creation failed!")
       }
       else
       {
           ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateTexture1D(&textureDesc,nullptr,&_texture1D)),"DX11Texture","Texture1D creation failed!")
       }


    }

    void DX11Texture::_CreateAs2D(const TextureCreateDesc &desc, DX11Device *pDevice)
    {
        D3D11_TEXTURE2D_DESC textureDesc = {};
        textureDesc.Width = desc.Width;
        textureDesc.Height = desc.Height;
        textureDesc.SampleDesc.Count = 1;
        textureDesc.SampleDesc.Quality = 0;
        textureDesc.Usage = DX11TextureUtils::GetUsage(desc.UsageFlags);
        textureDesc.BindFlags = DX11TextureUtils::GetBindFlags(desc.UsageFlags);
        textureDesc.Format = DX11TextureUtils::GetFormat(desc.Format);
        textureDesc.MipLevels = 1;
        textureDesc.MiscFlags = 0;
        textureDesc.CPUAccessFlags = DX11TextureUtils::GetCPUAccessFlags(desc.UsageFlags);
        textureDesc.ArraySize = 1;

        D3D11_SUBRESOURCE_DATA subresourceData = {};
        subresourceData.pSysMem = desc.pInitialData;
        subresourceData.SysMemPitch = 4*desc.Width; //TODO: implement texture format size utils
        subresourceData.SysMemSlicePitch = 0;

        if(desc.pInitialData != nullptr)
        {
            ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateTexture2D(&textureDesc,&subresourceData,&_texture2D)),"DX11Texture","Texture2D creation failed!");
        }
        else
        {
            ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateTexture2D(&textureDesc,nullptr,&_texture2D)),"DX11Texture","Texture2D creation failed!");
        }
    }

    void DX11Texture::_CreateAs3D(const TextureCreateDesc &desc, DX11Device *pDevice)
    {
        D3D11_TEXTURE3D_DESC textureDesc = {};
        textureDesc.Width = desc.Width;
        textureDesc.Height  =desc.Height;
        textureDesc.Depth = desc.Depth;
        textureDesc.Usage = DX11TextureUtils::GetUsage(desc.UsageFlags);
        textureDesc.BindFlags = DX11TextureUtils::GetBindFlags(desc.UsageFlags);
        textureDesc.Format = DX11TextureUtils::GetFormat(desc.Format);
        textureDesc.MipLevels = 1;
        textureDesc.MiscFlags = 0;
        textureDesc.CPUAccessFlags = DX11TextureUtils::GetCPUAccessFlags(desc.UsageFlags);

        D3D11_SUBRESOURCE_DATA subresourceData = {};
        subresourceData.pSysMem = desc.pInitialData;
        subresourceData.SysMemPitch = 0;
        subresourceData.SysMemSlicePitch = 0;

        if(desc.pInitialData != nullptr)
        {
            ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateTexture3D(&textureDesc,&subresourceData,&_texture3D)),"DX11Texture","Texture3D creation failed!");
        }
        else
        {
            ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateTexture3D(&textureDesc,nullptr,&_texture3D)),"DX11Texture","Texture3D creation failed!");
        }
    }
}