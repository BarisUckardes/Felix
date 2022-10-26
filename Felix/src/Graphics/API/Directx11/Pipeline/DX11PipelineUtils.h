//
// Created by Baris on 10/27/2022.
//

#ifndef FELIX_DX11PIPELINEUTILS_H
#define FELIX_DX11PIPELINEUTILS_H

#include <Graphics/Pipeline/PipelineCreateDesc.h>
#include <d3d11.h>
#include <dxgi.h>
namespace Felix
{
    class EXPORT DX11PipelineUtils {

    public:
        DX11PipelineUtils() = delete;
        ~DX11PipelineUtils() = delete;

        FORCEINLINE static DXGI_FORMAT GetInputElementDataFormat(const InputElementDataType type);
        FORCEINLINE static D3D11_COMPARISON_FUNC GetComparision(const DepthTestFunction function);
        FORCEINLINE static D3D11_FILL_MODE GetFillMode(const PolygonShadingMode mode);
        FORCEINLINE static D3D11_CULL_MODE GetCullMode(const CullMode mode);
        FORCEINLINE static D3D11_STENCIL_OP GetStencilOperation(const StencilOperation operation);
        FORCEINLINE static D3D11_DEPTH_STENCILOP_DESC GetStencilFaceDesc(const StencilFaceDesc& desc);

    };
}


#endif //FELIX_DX11PIPELINEUTILS_H
