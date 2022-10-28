//
// Created by Baris on 10/28/2022.
//

#ifndef FELIX_DX11RESOURCE_H
#define FELIX_DX11RESOURCE_H

#include <Graphics/Resource/GraphicsResource.h>
#include <Graphics/API/Directx11/Core/DX11Core.h>
#include <d3d11.h>

namespace Felix
{
    class EXPORT DX11Resource : public GraphicsResource {
    public:
        DX11Resource(const GraphicsResourceCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11Resource() override {}

        FORCEINLINE ID3D11ShaderResourceView* GetDXResourceView() const noexcept { return _resourceView.Get();}

    private:
        void _CreateAsTexture(GraphicsDeviceObject* pDeviceObject,DX11Device* pDevice);
        void _CreateAsSampler(GraphicsDeviceObject* pDeviceObject,DX11Device* pDevice);
        void _CreateAsConstantBuffer(GraphicsDeviceObject* pDeviceObject,DX11Device* pDevice);
    private:
        DXPTR<ID3D11ShaderResourceView> _resourceView;
    };

}

#endif //FELIX_DX11RESOURCE_H
