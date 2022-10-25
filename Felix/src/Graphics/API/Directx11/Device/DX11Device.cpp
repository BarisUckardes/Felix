//
// Created by Baris on 10/25/2022.
//

#include "DX11Device.h"
#include <Platform/Windows/Window/WindowsWindow.h>
#include <Graphics/API/Directx11/Framebuffer/DX11SwapchainFramebuffer.h>

namespace Felix
{
    DX11Device::DX11Device(const Felix::WindowGraphicsDeviceCreateDesc &desc, Felix::Window *pOwnerWindow) : GraphicsDevice(pOwnerWindow)
    {
        _CreateDX11Device();
    }
    DX11Device::DX11Device(const Felix::StandaloneGraphicsDeviceCreateDesc &desc)
    {
        _CreateDX11Device();
    }

    void DX11Device::_CreateDX11Device()
    {
        CreateDXGIFactory2(0,IID_PPV_ARGS(_factory.GetAddressOf()));

        int adapterIndex = 0;
        bool adapterFound = false;

        while(_factory->EnumAdapters1(adapterIndex,_adapter.GetAddressOf()) != DXGI_ERROR_NOT_FOUND)
        {
            DXGI_ADAPTER_DESC1 adapterDesc = {};
            _adapter->GetDesc1(&adapterDesc);

            if(adapterDesc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                adapterIndex++;
                continue;
            }

#ifdef FELIX_DEBUG
            D3D11CreateDevice(_adapter.Get(),D3D_DRIVER_TYPE_UNKNOWN,NULL,D3D11_CREATE_DEVICE_DEBUG,NULL,NULL,D3D11_SDK_VERSION,&_device,NULL,&_context);
#else
            D3D11CreateDevice(_adapter.Get(),D3D_DRIVER_TYPE_UNKNOWN,NULL,NULL,NULL,NULL,D3D11_SDK_VERSION,&_device,NULL,&_context);
#endif

            adapterFound = true;
            adapterIndex++;
            break;
        }

        ASSERT(adapterFound,"DX11Device","Directx 11 compatible graphics device couldnt be found!");
    }
    DX11Device::~DX11Device()
    {

    }

    void DX11Device::SwapbuffersCore()
    {
        ((DX11SwapchainFramebuffer*)GetSwapchainFramebuffer())->GetDXSwapchain()->Present(1u,0);
    }

    CommandBuffer *DX11Device::CreateCommandBufferCore(const CommandBufferCreateDesc &desc) {
        return nullptr;
    }

    GraphicsBuffer *DX11Device::CreateBufferCore(const GraphicsBufferCreateDesc &desc) {
        return nullptr;
    }

    Shader *DX11Device::CreateShaderCore(const ShaderCreateDesc &desc) {
        return nullptr;
    }

    Texture *DX11Device::CreateTextureCore(const TextureCreateDesc &desc) {
        return nullptr;
    }

    Framebuffer *DX11Device::CreateFramebufferCore(const FramebufferCreateDesc &desc) {
        return nullptr;
    }

    Framebuffer* DX11Device::CreateSwapchainFramebufferCore(const SwapchainFramebufferCreateDesc &desc)
    {
        return new DX11SwapchainFramebuffer(desc,GetOwnerWindow());
    }

    GraphicsResource *DX11Device::CreateResourceCore(const GraphicsResourceCreateDesc &desc) {
        return nullptr;
    }

    Pipeline *DX11Device::CreatePipelineCore(const PipelineCreateDesc &desc) {
        return nullptr;
    }

    TextureSampler *DX11Device::CreateTextureSamplerCore(const TextureSamplerCreateDesc &desc) {
        return nullptr;
    }

    void DX11Device::UpdateBufferCore(GraphicsBuffer *pBuffer, const GraphicsBufferUpdateDesc &desc) {

    }

    void DX11Device::UpdateTextureCore(Texture *pTexture, const TextureUpdateDesc &desc) {

    }
}