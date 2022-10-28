//
// Created by Baris on 10/28/2022.
//

#include "DX11Framebuffer.h"
#include <Graphics/API/Directx11/Texture/DX11Texture.h>
#include <Graphics/API/Directx11/Texture/DX11TextureUtils.h>
#include <Graphics/API/Directx11/Device/DX11Device.h>

namespace Felix
{
    DX11Framebuffer::DX11Framebuffer(const FramebufferCreateDesc &desc, DX11Device *pDevice) : Framebuffer(desc,false)
    {
        /*
         * Create color render targets
         */
        for(unsigned char i = 0;i<desc.Attachments.size();i++)
        {
            const DX11Texture *pTexture = (const DX11Texture *) desc.Attachments[i];

            D3D11_RENDER_TARGET_VIEW_DESC rtvDesc = {};
            rtvDesc.Format = DX11TextureUtils::GetFormat(pTexture->GetFormat());
            rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
            rtvDesc.Texture2D.MipSlice = 0;

            DXPTR<ID3D11RenderTargetView> pRtv = nullptr;
            ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateRenderTargetView(pTexture->GetDXTexture2D(),&rtvDesc,&pRtv)),"DX11Framebuffer","Failed to create render target view");

            _rtvs.push_back(pRtv);
            _rtvsOut.push_back(pRtv.Get());
        }

        /*
         * Create depth stencil targets
         */
        const DX11Texture* pDepthStencilTexture = nullptr;
        for(unsigned char i = 0;i<desc.Attachments.size();i++)
        {
            const Texture* pTexture = desc.Attachments[i];

            if(pTexture->GetUsageFlags() & TextureUsage::DepthStencilTarget)
            {
                pDepthStencilTexture = (const DX11Texture*)pTexture;
                break;
            }
        }

        if(pDepthStencilTexture != nullptr)
        {
            D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
            dsvDesc.Format = DX11TextureUtils::GetFormat(pDepthStencilTexture->GetFormat());
            dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
            dsvDesc.Texture2D.MipSlice = 0;

            ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateDepthStencilView(pDepthStencilTexture->GetDXTexture2D(),&dsvDesc,&_dsv)),"DX11Framebuffer","Failed to create depth stencil view");
        }
    }

    DX11Framebuffer::~DX11Framebuffer()
    {

    }


}