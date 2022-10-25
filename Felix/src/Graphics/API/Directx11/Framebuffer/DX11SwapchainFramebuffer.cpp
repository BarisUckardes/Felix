//
// Created by Baris on 10/25/2022.
//

#include "DX11SwapchainFramebuffer.h"
#include <Platform/Windows/Window/WindowsWindow.h>
#include <Graphics/API/Directx11/Device/DX11Device.h>

Felix::DX11SwapchainFramebuffer::DX11SwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc, Window* pOwnerWindow) : SwapchainFramebuffer(swapchainDesc,pOwnerWindow)
{
    const WindowsWindow* pWin32Window = (const WindowsWindow*)pOwnerWindow;
    const DX11Device* pDX11Device = (const DX11Device*)pOwnerWindow->GetChildDevice();
    ID3D11Device* pDevice = pDX11Device->GetDXDevice();
    IDXGIFactory4* pFactory = pDX11Device->GetDXFactory();


    DXGI_MODE_DESC bufferDesc = {0};
    bufferDesc.Width = swapchainDesc.Width;
    bufferDesc.Height = swapchainDesc.Height;
    bufferDesc.RefreshRate.Numerator = 60; // implement adaptive
    bufferDesc.RefreshRate.Denominator = 1;
    bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    DXGI_SWAP_CHAIN_DESC dx11SwapchainDesc = {0};
    dx11SwapchainDesc.BufferDesc = bufferDesc;
    dx11SwapchainDesc.SampleDesc.Count = 1;
    dx11SwapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    dx11SwapchainDesc.BufferCount = swapchainDesc.BufferCount;
    dx11SwapchainDesc.OutputWindow = pWin32Window->GetWin32WindowHandle();
    dx11SwapchainDesc.Windowed = true;
    dx11SwapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

    ASSERT(SUCCEEDED(pFactory->CreateSwapChain(pDevice,&dx11SwapchainDesc,&_swapchain)),"DX11SwapchainFramebuffer","Failed to create the swapchain");
    ASSERT(SUCCEEDED(pFactory->MakeWindowAssociation(pWin32Window->GetWin32WindowHandle(),DXGI_MWA_NO_ALT_ENTER)),"DX11SwapchainFramebuffer","Make window association failed!");

    /*
     * Create buffers
     */
    for(unsigned char i = 0;i<swapchainDesc.BufferCount;i++)
    {
        /*
         * Created backbuffer
         */
        ID3D11Texture2D* pBackBuffer;
        _swapchain->GetBuffer(i,__uuidof(ID3D11Texture2D),(void**)&pBackBuffer);

        /*
         * Create render target
         */
        DXPTR<ID3D11RenderTargetView> renderTargetView;
        pDevice->CreateRenderTargetView(pBackBuffer,nullptr,&renderTargetView);
        _renderTargetViews.push_back(renderTargetView);

        /*
         * Release backbuffer
         */
        pBackBuffer->Release();
    }
}

Felix::DX11SwapchainFramebuffer::~DX11SwapchainFramebuffer()
{

}

void Felix::DX11SwapchainFramebuffer::OnResizeCore(const unsigned int width, const unsigned int Height)
{
    _renderTargetViews.clear();
    _swapchain->ResizeBuffers(0,0,0, DXGI_FORMAT_UNKNOWN, 0);
}

