//
// Created by Baris on 10/25/2022.
//

#ifndef STBI_DX11SWAPCHAINFRAMEBUFFER_H
#define STBI_DX11SWAPCHAINFRAMEBUFFER_H

#include <Graphics/Framebuffer/SwapchainFramebuffer.h>
#include <Graphics/API/Directx11/Core/DX11Core.h>

namespace Felix
{
    class EXPORT DX11SwapchainFramebuffer : public SwapchainFramebuffer{

    public:
        DX11SwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc, Window* pOwnerWindow);
        virtual ~DX11SwapchainFramebuffer() override;

        FORCEINLINE IDXGISwapChain* GetDXSwapchain() const noexcept { return _swapchain.Get();}
        FORCEINLINE ID3D11RenderTargetView* GetSwapchainRTV() const noexcept { return _renderTargetViews[0].Get();}
        FORCEINLINE ID3D11DepthStencilView* GetSwapchainDSV() const noexcept { return _depthStencilView.Get();}
    protected:
        void OnResizeCore(const unsigned int width, const unsigned int Height) override;

    private:
        DXPTR<IDXGISwapChain> _swapchain;
        std::vector<DXPTR<ID3D11RenderTargetView>> _renderTargetViews;
        DXPTR<ID3D11DepthStencilView> _depthStencilView;
    };

}

#endif //STBI_DX11SWAPCHAINFRAMEBUFFER_H
