#pragma once
#include <Graphics/Pipeline/PipelineCreateDesc.h>
#include <d3d12.h>

namespace Felix
{
	class EXPORT DX12PipelineUtils
	{
	public:
		DX12PipelineUtils() = delete;
		~DX12PipelineUtils() = delete;

		FORCEINLINE static D3D12_SHADER_VISIBILITY GetShaderVisibility(const ShaderType type);
		FORCEINLINE static std::string GetInputElementSemanticName(const InputElementSemantic semantic);

	};
}