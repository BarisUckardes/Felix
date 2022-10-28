//
// Created by Baris on 10/28/2022.
//

#ifndef FELIX_DX11FRAMEBUFFER_H
#define FELIX_DX11FRAMEBUFFER_H


#include <Graphics/API/Directx11/Core/DX11Core.h>
#include <Graphics/Framebuffer/Framebuffer.h>
#include <d3d11.h>

namespace Felix
{
    class EXPORT DX11Framebuffer : public Framebuffer {
    public:
        DX11Framebuffer(const FramebufferCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11Framebuffer() override;

        FORCEINLINE std::vector<ID3D11RenderTargetView*> GetDX11Rtv() const noexcept { return _rtvsOut;}
        FORCEINLINE ID3D11DepthStencilView* GEtDX11Dsv() const noexcept { return _dsv.Get();}
    private:
        std::vector<DXPTR<ID3D11RenderTargetView>> _rtvs;
        std::vector<ID3D11RenderTargetView*> _rtvsOut;
        DXPTR<ID3D11DepthStencilView> _dsv;
    };

}

#endif //FELIX_DX11FRAMEBUFFER_H
