#ifdef FELIX_OS_WINDOWS
//
// Created by Baris on 10/28/2022.
//

#include "DX11Resource.h"
#include <Graphics/API/Directx11/Texture/DX11TextureUtils.h>
#include <Graphics/API/Directx11/Texture/DX11Texture.h>
#include <Graphics/API/Directx11/Texture/DX11TextureSampler.h>
#include <Graphics/API/Directx11/Device/DX11Device.h>
#include <Graphics/API/Directx11/Buffer/DX11Buffer.h>
#include <Graphics/API/Directx/DXGI/DXGIUtils.h>

namespace Felix
{
    DX11Resource::DX11Resource(const GraphicsResourceCreateDesc& desc,DX11Device* pDevice) : GraphicsResource(desc)
    {
        switch(desc.Type)
        {
            case GraphicsResourceType::Texture:
            {
                _CreateAsTexture(desc.pDeviceObject,pDevice);
                break;
            }
            case GraphicsResourceType::TextureSampler:
            {
                _CreateAsSampler(desc.pDeviceObject,pDevice);
                break;
            }
            case GraphicsResourceType::ConstantBuffer:
            {
                _CreateAsConstantBuffer(desc.pDeviceObject,pDevice);
                break;
            }
        }
    }

    void DX11Resource::_CreateAsTexture(GraphicsDeviceObject *pDeviceObject, DX11Device *pDevice)
    {
        const Texture* pTexture = (const Texture*)pDeviceObject;
        const DX11Texture* pDX11Texture = (const DX11Texture*)pTexture;

        D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
        srvDesc.Format = DXGIUtils::GetFormat(pTexture->GetFormat());
        srvDesc.Texture2D.MipLevels = -1;
        srvDesc.Texture2D.MostDetailedMip = 0;

        ID3D11Resource* pDX11Resource = nullptr;
        switch(pTexture->GetTextureType())
        {
            case TextureType::Texture1D:
            {
                srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1D;
                pDX11Resource = pDX11Texture->GetDXTexture1D();
                break;
            }
            case TextureType::Texture2D:
            {
                srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
                pDX11Resource = pDX11Texture->GetDXTexture2D();
                break;
            }
            case TextureType::Texture3D:
            {
                srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE3D;
                pDX11Resource = pDX11Texture->GetDXTexture3D();
                break;
            }
            case TextureType::CubeTexture:
            {
                srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURECUBE;

                break;
            }
        }

        ASSERT(SUCCEEDED( pDevice->GetDXDevice()->CreateShaderResourceView(pDX11Resource,&srvDesc,&_resourceView)),"DX11Resource","Failed to create texture shader resource view for the shader");
    }

    void DX11Resource::_CreateAsSampler(GraphicsDeviceObject *pDeviceObject, DX11Device *pDevice)
    {

    }

    void DX11Resource::_CreateAsConstantBuffer(GraphicsDeviceObject *pDeviceObject, DX11Device *pDevice)
    {
//        D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
//        ZeroMemory(&srvDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
//        srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
//
//        ID3D11Resource* pDX11Resource = ((const DX11Buffer*)pDeviceObject)->GetDX11Buffer();
//
//        ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateShaderResourceView(pDX11Resource,&srvDesc,&_resourceView)),"DX11Resource","Failed to create constant buffer shader resource view for the shader");
    }
}
#endif