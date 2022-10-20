#pragma once
#include <Graphics/Pipeline/Pipeline.h>

namespace Felix
{
	/// <summary>
	/// OpenGL implementation of the pipeline
	/// </summary>
	class EXPORT OpenGLPipeline : public Pipeline
	{
	public:
		struct StencilGLFaceDesc
		{
			unsigned int StencilReferenceValue;
			unsigned int StencilWriteMask;
			unsigned int StencilReadMask;
			unsigned int Function;
			unsigned int FailOperation;
			unsigned int PassOperation;
			unsigned int DepthFailOperation;
		};
		struct PipelineResource
		{
			unsigned int UniformIndex;
			unsigned int UniformBlockBindingPoint;
			unsigned int UniformBlockIndex;
		};
	public:
		OpenGLPipeline(const PipelineCreateDesc& desc);
		virtual ~OpenGLPipeline() override;

		FORCEINLINE std::vector<PipelineResource> GetGLResources() const noexcept { return _resources; }
		FORCEINLINE unsigned int GetGLProgramHandle() const noexcept { return _programHandle; }
		FORCEINLINE unsigned int GetGLPrimitives() const noexcept { return _primitives; }
		FORCEINLINE unsigned int GetGLFrontFace() const noexcept { return _frontFace; }
		FORCEINLINE unsigned int GetGLCullFace() const noexcept { return _cullFace; }
		FORCEINLINE unsigned int GetGLDepthFunction() const noexcept { return _depthFunction; }
		FORCEINLINE unsigned int GetGLShadingMode() const noexcept { return _shadingMode; }
		FORCEINLINE StencilGLFaceDesc GetGLStencilFrontDesc() const noexcept { return _stencilFrontFace; }
		FORCEINLINE StencilGLFaceDesc GetGLStencilBackDesc() const noexcept { return _stencilBackFace; }
		FORCEINLINE unsigned int GetColorBlendingFunction() const noexcept { return _colorBlendingFunction; }
		FORCEINLINE unsigned int GetAlphaBlendingFunction() const noexcept { return _alphaBlendingFunction; }
		FORCEINLINE unsigned int GetSourceColorFactor() const noexcept { return _sourceColorFactor; }
		FORCEINLINE unsigned int GetDestinationColorFactor() const noexcept { return _destinationColorFactor; }
		FORCEINLINE unsigned int GetSourceAlphaFactor() const noexcept { return _sourceAlphaFactor; }
		FORCEINLINE unsigned int GetDestinationAlphaFactor() const noexcept { return _destinationAlphaFactor; }

	private:
		std::vector<PipelineResource> _resources;
		unsigned int _uniformBlockCount;
		unsigned int _programHandle;
		unsigned int _primitives;
		unsigned int _frontFace;
		unsigned int _cullFace;
		unsigned int _depthFunction;
		unsigned int _shadingMode;
		StencilGLFaceDesc _stencilFrontFace;
		StencilGLFaceDesc _stencilBackFace;
		unsigned int _colorBlendingFunction;
		unsigned int _alphaBlendingFunction;
		unsigned int _sourceColorFactor;
		unsigned int _destinationColorFactor;
		unsigned int _sourceAlphaFactor;
		unsigned int _destinationAlphaFactor;
	};
}