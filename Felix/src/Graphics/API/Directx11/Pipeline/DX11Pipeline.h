//
// Created by Baris on 10/27/2022.
//

#ifndef FELIX_DX11PIPELINE_H
#define FELIX_DX11PIPELINE_H

#include <Graphics/Pipeline/Pipeline.h>
#include <Graphics/API/Directx11/Core/DX11Core.h>

namespace Felix
{
    class EXPORT DX11Pipeline : public Pipeline{
    public:
        DX11Pipeline(const PipelineCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11Pipeline() override;

    private:
        DXPTR<ID3D11InputLayout> _inputLayout;
        DXPTR<ID3D11RasterizerState> _rasterizerState;
        DXPTR<ID3D11DepthStencilState> _depthStencilState;
        DXPTR<ID3D11BlendState> _blendState;

    };


}
#endif //FELIX_DX11PIPELINE_H
