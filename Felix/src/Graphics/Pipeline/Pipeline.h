#pragma once
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Pipeline/PipelineCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// Represents a complete pipeline state for the gpu
	/// </summary>
	class EXPORT Pipeline : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE RasterizerStateDesc GetRasterizerDesc() const noexcept { return _rasterizerDesc; }
		FORCEINLINE DepthStencilStateDesc GetDepthStencilDesc() const noexcept { return _depthStencilDesc; }
		FORCEINLINE BlendingStateDesc GetBlendingDesc() const noexcept { return _blendingDesc; }
		FORCEINLINE VertexLayoutDesc GetInputLayoutDesc() const noexcept { return _inputLayoutDesc; }
		FORCEINLINE ShadingPassDesc GetShadingPassDesc() const noexcept { return _shadingPassDesc; }
		FORCEINLINE OutputDesc GetOutputDesc() const noexcept { return _outputDesc; }
		FORCEINLINE PipelineType GetPipelineType() const noexcept { return _type; }

	protected:
		Pipeline(const PipelineCreateDesc& desc) :
			_rasterizerDesc(desc.RasterizerDesc),
			_depthStencilDesc(desc.DepthStencilDesc),
			_blendingDesc(desc.BlendingDesc),
			_inputLayoutDesc(desc.InputLayoutDesc),
			_shadingPassDesc(desc.ShadingPass),
			_outputDesc(desc.OutputDesc),
			_type(desc.Type)
		{}
		virtual ~Pipeline() {}

	private:
		const RasterizerStateDesc _rasterizerDesc;
		const DepthStencilStateDesc _depthStencilDesc;
		const BlendingStateDesc _blendingDesc;
		const VertexLayoutDesc _inputLayoutDesc;
		const ShadingPassDesc _shadingPassDesc;
		const OutputDesc _outputDesc;
		const PipelineType _type;
	};
}