//
// Created by Baris on 10/27/2022.
//

#include "DX11PipelineUtils.h"

namespace Felix
{
    DXGI_FORMAT DX11PipelineUtils:: GetInputElementDataFormat(const InputElementDataType type)
    {
        switch(type)
        {
                    case InputElementDataType::Boolean:
                        return DXGI_FORMAT_R8_UNORM;
                    case InputElementDataType::Integer:
                        return DXGI_FORMAT_R32_SINT;
                    case InputElementDataType::Integer2:
                        return DXGI_FORMAT_R32G32_SINT;
                    case InputElementDataType::Integer3:
                        return DXGI_FORMAT_R32G32B32_SINT;
                    case InputElementDataType::Integer4:
                        return DXGI_FORMAT_R32G32B32A32_SINT;
                    case InputElementDataType::UnsignedInteger:
                        return DXGI_FORMAT_R32_UINT;
                    case InputElementDataType::UnsignedInteger2:
                        return DXGI_FORMAT_R32G32_UINT;
                    case InputElementDataType::UnsignedInteger3:
                        return DXGI_FORMAT_R32G32B32_UINT;
                    case InputElementDataType::UnsignedInteger4:
                        return DXGI_FORMAT_R32G32B32A32_UINT;
                    case InputElementDataType::Float:
                        return DXGI_FORMAT_R32_FLOAT;
                    case InputElementDataType::Float2:
                        return DXGI_FORMAT_R32G32_FLOAT;
                    case InputElementDataType::Float3:
                        return DXGI_FORMAT_R32G32B32_FLOAT;
                    case InputElementDataType::Float4:
                        return DXGI_FORMAT_R32G32B32A32_FLOAT;
                    case InputElementDataType::Matrix3x3:
                        return DXGI_FORMAT_R32_SINT;
                    case InputElementDataType::Matrix4x4:
                        return DXGI_FORMAT_R32_SINT;
            default:
                ASSERT(false,"DX11PipelineUtils","Invalid InputElementDataType!");
        }
    }

    D3D11_COMPARISON_FUNC DX11PipelineUtils::GetComparision(const DepthTestFunction function)
    {
        switch (function)
        {
            case DepthTestFunction::Always0:
                return D3D11_COMPARISON_ALWAYS;
            case DepthTestFunction::Never:
                return D3D11_COMPARISON_NEVER;
            case DepthTestFunction::Less:
                return D3D11_COMPARISON_LESS;
            case DepthTestFunction::Equal:
                return D3D11_COMPARISON_EQUAL;
            case DepthTestFunction::LessEqual:
                return D3D11_COMPARISON_LESS_EQUAL;
            case DepthTestFunction::Greater:
                return D3D11_COMPARISON_GREATER;
            case DepthTestFunction::NotEqual:
                return D3D11_COMPARISON_NOT_EQUAL;
            case DepthTestFunction::GreatEqual:
                return D3D11_COMPARISON_GREATER_EQUAL;
            default:
                ASSERT(false,"DX11Pipeline","Invalid DepthTestFunction");
        }
    }

    D3D11_STENCIL_OP DX11PipelineUtils::GetStencilOperation(const StencilOperation operation)
    {
        switch (operation)
        {
            case StencilOperation::Keep:
                return D3D11_STENCIL_OP_KEEP;
            case StencilOperation::Zero:
                return D3D11_STENCIL_OP_ZERO;
            case StencilOperation::Replace:
                return D3D11_STENCIL_OP_REPLACE;
            case StencilOperation::Increment:
                return D3D11_STENCIL_OP_INCR;
            case StencilOperation::IncrementWrap:
                return D3D11_STENCIL_OP_INCR_SAT;
            case StencilOperation::Decrement:
                return D3D11_STENCIL_OP_DECR;
            case StencilOperation::DecrementWrap:
                return D3D11_STENCIL_OP_DECR_SAT;
            case StencilOperation::Invert:
                return D3D11_STENCIL_OP_INVERT;
            default:
                ASSERT(false,"DX11PipelineUtils","Invalid StencilOperation");
        }
    }

    D3D11_DEPTH_STENCILOP_DESC DX11PipelineUtils::GetStencilFaceDesc(const StencilFaceDesc &desc)
    {
        D3D11_DEPTH_STENCILOP_DESC faceDesc = {};
        faceDesc.StencilFunc = D3D11_COMPARISON_ALWAYS;
        faceDesc.StencilDepthFailOp = GetStencilOperation(desc.DepthFailOperation);
        faceDesc.StencilFailOp = GetStencilOperation(desc.FailOperation);
        faceDesc.StencilPassOp = GetStencilOperation(desc.PassOperation);
        return faceDesc;
    }

    D3D11_FILL_MODE DX11PipelineUtils::GetFillMode(const PolygonShadingMode mode)
    {
        switch (mode)
        {
            case PolygonShadingMode::Wireframe:
                return D3D11_FILL_WIREFRAME;
            case PolygonShadingMode::Points:
                return D3D11_FILL_WIREFRAME;
            case PolygonShadingMode::Solid:
                return D3D11_FILL_SOLID;
            default:
                ASSERT(false,"DX11PipelineUtils","Invalid PolygonShadingMode!");
        }
    }

    D3D11_CULL_MODE DX11PipelineUtils::GetCullMode(const CullMode mode)
    {
        switch (mode)
        {
            case CullMode::None0:
                return D3D11_CULL_NONE;
            case CullMode::Front:
                return D3D11_CULL_FRONT;
            case CullMode::Back:
                return D3D11_CULL_BACK;
            case CullMode::FrontAndBack:
                return   D3D11_CULL_BACK;
            default:
                ASSERT(false,"DX11Pipeline","Invalid CullMode!");
        }
    }
}