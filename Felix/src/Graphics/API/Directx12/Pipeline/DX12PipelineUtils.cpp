#include "DX12PipelineUtils.h"

namespace Felix
{
    D3D12_SHADER_VISIBILITY DX12PipelineUtils::GetShaderVisibility(ShaderType type)
    {
		switch (type)
		{
		case Felix::ShaderType::Vertex:
			return D3D12_SHADER_VISIBILITY_VERTEX;
		case Felix::ShaderType::Fragment:
			return D3D12_SHADER_VISIBILITY_PIXEL;
		case Felix::ShaderType::Geometry:
			return D3D12_SHADER_VISIBILITY_GEOMETRY;
			break;
		case Felix::ShaderType::TesellationEval:
			break;
		case Felix::ShaderType::TesellationControl:
			break;
		case Felix::ShaderType::Compute:
			break;
		default:
			break;
		}
    }
    std::string DX12PipelineUtils::GetInputElementSemanticName(const InputElementSemantic semantic)
    {
        std::string output;

        switch (semantic)
        {
        case InputElementSemantic::Position:
        {
            output = "POSITION";
            break;
        }
        case InputElementSemantic::Normal:
        {
            output = "NORMAL";
            break;
        }
        case InputElementSemantic::Color:
        {
            output = "COLOR";
            break;
        }
        case InputElementSemantic::TextureCoordinate:
        {
            output = "TEXCOORD";
            break;
        }
        default:
            ASSERT(false, "DX11PipelineUtils", "Invalid InputElementSemantic");
        }
        return output;
    }
}