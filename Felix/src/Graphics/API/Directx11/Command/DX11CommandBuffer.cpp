//
// Created by Baris on 10/26/2022.
//

#include "DX11CommandBuffer.h"
#include <Graphics/API/Directx11/Device/DX11DeviceObjects.h>

namespace Felix
{
    DX11CommandBuffer::DX11CommandBuffer(const Felix::CommandBufferCreateDesc &desc,ID3D11Device* pDevice,ID3D11DeviceContext* pContext) : CommandBuffer(desc)
    {
        _dx11Device = pDevice;
        _dx11Context = pContext;
    }

    DX11CommandBuffer::~DX11CommandBuffer()
    {

    }

    void DX11CommandBuffer::LockCore()
    {

    }

    void DX11CommandBuffer::UnlockCore()
    {

    }

    void DX11CommandBuffer::BindPipelineCore(Pipeline *pPipeline)
    {
        const DX11Pipeline* pDX11Pipeline = (const DX11Pipeline*)pPipeline;

        /*
         * Set rasterizer state
         */
        _dx11Context->RSSetState(pDX11Pipeline->GetRasterizerState());

        /*
         * Set depth stencil state
         */
        _dx11Context->OMSetDepthStencilState(pDX11Pipeline->GetDepthStencilState(),0);

        /*
         * Set blending
         */
        float blendFactor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        UINT sampleMask   = 0xffffffff;
        _dx11Context->OMSetBlendState(pDX11Pipeline->GetBlendingState(),blendFactor,sampleMask);

        /*
         * Set input layout
         */
        _dx11Context->IASetInputLayout(pDX11Pipeline->GetInputLayout());

        /*
         * Set topology
         */
        _dx11Context->IASetPrimitiveTopology(pDX11Pipeline->GetPrimitives());

        /*
         * Set shaders
         */
        const ShadingPassDesc& shadingDesc = pPipeline->GetShadingPassDesc();
        for(unsigned char i = 0;i<shadingDesc.Shaders.size();i++)
        {
            const Shader* pShader = shadingDesc.Shaders[i];

            switch(pShader->GetShaderType())
            {
                case ShaderType::Vertex:
                {
                    const DX11VertexShader* pVertexShader = (const DX11VertexShader*)pShader;
                    _dx11Context->VSSetShader(pVertexShader->GetVertexShader(),nullptr,0);
                    break;
                }
                case ShaderType::Fragment:
                {
                    const DX11PixelShader* pPixelShader = (const DX11PixelShader*)pShader;
                    _dx11Context->PSSetShader(pPixelShader->GetPixelShader(),nullptr,0);
                    break;
                }
                case ShaderType::Geometry:
                {
                    break;
                }
                case ShaderType::TesellationEval:
                {
                    break;
                }
                case ShaderType::TesellationControl:
                {
                    break;
                }
                case ShaderType::Compute:
                {
                    break;
                }
            }
        }
    }

    void DX11CommandBuffer::BindFramebufferCore(Framebuffer *pFramebuffer)
    {
        ID3D11RenderTargetView* pRtv = nullptr;
        ID3D11DepthStencilView* pDsv = nullptr;

        if(pFramebuffer->IsSwapchain())
        {
            const DX11SwapchainFramebuffer* pDX11SwapchainFramebuffer = (const DX11SwapchainFramebuffer*)pFramebuffer;
            pRtv = pDX11SwapchainFramebuffer->GetSwapchainRTV();
            pDsv = pDX11SwapchainFramebuffer->GetSwapchainDSV();
        }
        else
        {
            pDsv = nullptr;
        }

        ASSERT(pRtv != nullptr,"DX11CommandBuffer","Invalid framebuffer, cannot bind rtv as the current render target");

        _dx11Context->OMSetRenderTargets(1,&pRtv,pDsv);
    }

    void DX11CommandBuffer::SetViewportCore(const ViewportDesc &desc)
    {
        D3D11_VIEWPORT viewport = {};
        viewport.Width = desc.Width;
        viewport.Height = desc.Height;
        viewport.MinDepth = desc.MinDepth;
        viewport.MaxDepth = desc.MaxDepth;
        viewport.TopLeftX = desc.PositionX;
        viewport.TopLeftY = desc.PositionY;

        _dx11Context->RSSetViewports(1,&viewport);
    }

    void DX11CommandBuffer::SetScissorsCore(const ScissorsDesc &desc)
    {
        D3D11_RECT rect = {};
        _dx11Context->RSSetScissorRects(1,&rect);
    }

    void DX11CommandBuffer::ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b,
                                           const unsigned char a)
                                           {
        const Framebuffer* pFramebuffer = GetBoundFramebuffer();

        ID3D11RenderTargetView* pRtv = nullptr;
        if(pFramebuffer->IsSwapchain())
        {
            const DX11SwapchainFramebuffer* pDX11SwapchainFramebuffer = (const DX11SwapchainFramebuffer*)pFramebuffer;
            pRtv = pDX11SwapchainFramebuffer->GetSwapchainRTV();
        }
        else
        {
            pRtv = nullptr;
        }

        ASSERT(pRtv != nullptr,"DX11CommandBuffer","Invalid framebuffer, cannot clear the color buffer");

        const FLOAT dxColor[] = {(FLOAT)r,(FLOAT)g,(FLOAT)b,(FLOAT)a};

        _dx11Context->ClearRenderTargetView(pRtv,dxColor);
    }

    void DX11CommandBuffer::ClearDepthCore(const unsigned char depth)
    {
        const Framebuffer* pFramebuffer = GetBoundFramebuffer();

        ID3D11DepthStencilView* pDsv = nullptr;
        if(pFramebuffer->IsSwapchain())
        {
            const DX11SwapchainFramebuffer* pDX11SwapchainFramebuffer = (const DX11SwapchainFramebuffer*)pFramebuffer;
            pDsv = pDX11SwapchainFramebuffer->GetSwapchainDSV();
        }
        else
        {
            pDsv = nullptr;
        }

        ASSERT(pDsv != nullptr,"DX11CommandBuffer","Invalid framebuffer, cannot clear the depth&stencil buffer");

        _dx11Context->ClearDepthStencilView(pDsv,D3D11_CLEAR_DEPTH,depth,0);
    }

    void DX11CommandBuffer::ClearStencilCore(const int stencil)
    {
        const Framebuffer* pFramebuffer = GetBoundFramebuffer();

        ID3D11DepthStencilView* pDsv = nullptr;
        if(pFramebuffer->IsSwapchain())
        {
            pDsv = nullptr;
        }
        else
        {
            pDsv = nullptr;
        }

        _dx11Context->ClearDepthStencilView(pDsv,D3D11_CLEAR_STENCIL,0,stencil);
    }

    void DX11CommandBuffer::SetVertexBufferCore(GraphicsBuffer *pBuffer)
    {
        const DX11Buffer* pDX11Buffer = (const DX11Buffer*)pBuffer;

        ID3D11Buffer* pBufferBase = pDX11Buffer->GetDX11Buffer();
        const unsigned int stride = pBuffer->GetSubItemSize();
        const unsigned int offset = 0;

        _dx11Context->IASetVertexBuffers(0,1,&pBufferBase,&stride,&offset);
    }

    void DX11CommandBuffer::SetIndexBufferCore(GraphicsBuffer *pBuffer)
    {
        const DX11Buffer* pDX11Buffer = (const DX11Buffer*)pBuffer;

        ID3D11Buffer* pBufferBase = pDX11Buffer->GetDX11Buffer();

        _dx11Context->IASetIndexBuffer(pBufferBase,DXGI_FORMAT_R32_UINT,0);
    }

    void DX11CommandBuffer::CommitResourceCore(const unsigned int slotIndex, GraphicsResource *pResource)
    {
        const DX11Resource* pDX11Resource = (const DX11Resource*)pResource;
        const ShaderType targetStage = GetBoundPipeline()->GetResourceStateDesc().SlotDescriptions[slotIndex].Stage;

        switch(pResource->GetResourceType())
        {
            case GraphicsResourceType::Texture:
            {
                const DX11Resource* pDX11Resource = (const DX11Resource*)pResource;
                _CommitResourceAsTexture(slotIndex,targetStage,pDX11Resource);

                break;
            }
            case GraphicsResourceType::TextureSampler:
            {
                const DX11TextureSampler* pDX11Sampler = (const DX11TextureSampler*)pResource->GetResource();
                _CommitResourceAsSampler(slotIndex,targetStage,pDX11Sampler);

                break;
            }
            case GraphicsResourceType::ConstantBuffer:
            {
                const DX11Buffer* pDX11Buffer = (const DX11Buffer*)pResource->GetResource();
                _CommitResourceAsConstantBuffer(slotIndex,targetStage,pDX11Buffer);
                break;
            }
        }
    }
    void DX11CommandBuffer::_CommitResourceAsTexture(const unsigned int slotIndex,const ShaderType targetStage,const DX11Resource* pResource)
    {
        ID3D11ShaderResourceView* pSrv = pResource->GetDXResourceView();

        switch(targetStage)
        {
            case ShaderType::Vertex:
            {

                _dx11Context->VSSetShaderResources(0,1,&pSrv);
                break;
            }
            case ShaderType::Fragment:
            {
                _dx11Context->PSSetShaderResources(0,1,&pSrv);
                break;
            }
            case ShaderType::Geometry:
            {
                break;
            }
            case ShaderType::TesellationEval:
            {
                break;
            }
            case ShaderType::TesellationControl:
            {
                break;
            }
            case ShaderType::Compute:
            {
                break;
            }
        }
    }

    void DX11CommandBuffer::_CommitResourceAsSampler(const unsigned int slotIndex,const ShaderType targetStage,const DX11TextureSampler *pSampler)
    {
        ID3D11SamplerState* pDX11Sampler = pSampler->GetDX11Sampler();

        switch(targetStage)
        {
            case ShaderType::Vertex:
            {

                _dx11Context->VSSetSamplers(0,1,&pDX11Sampler);
                break;
            }
            case ShaderType::Fragment:
            {
                _dx11Context->PSSetSamplers(0,1,&pDX11Sampler);
                break;
            }
            case ShaderType::Geometry:
            {
                break;
            }
            case ShaderType::TesellationEval:
            {
                break;
            }
            case ShaderType::TesellationControl:
            {
                break;
            }
            case ShaderType::Compute:
            {
                break;
            }
        }
    }

    void DX11CommandBuffer::_CommitResourceAsConstantBuffer(const unsigned int slotIndex,const ShaderType targetStage,const DX11Buffer* pBuffer)
    {
        ID3D11Buffer * pDX11Buffer = pBuffer->GetDX11Buffer();

        switch(targetStage)
        {
            case ShaderType::Vertex:
            {

                _dx11Context->VSSetConstantBuffers(0,1,&pDX11Buffer);
                break;
            }
            case ShaderType::Fragment:
            {
                _dx11Context->PSSetConstantBuffers(0,1,&pDX11Buffer);
                break;
            }
            case ShaderType::Geometry:
            {
                break;
            }
            case ShaderType::TesellationEval:
            {
                break;
            }
            case ShaderType::TesellationControl:
            {
                break;
            }
            case ShaderType::Compute:
            {
                break;
            }
        }
    }

    void DX11CommandBuffer::DrawIndexedCore(const unsigned int indexCount)
    {
        _dx11Context->DrawIndexed(indexCount,0,0);
    }

    void DX11CommandBuffer::ClearCachedStateCore()
    {
        _currentViewport = {0,0,0,0,0,0};
    }


}