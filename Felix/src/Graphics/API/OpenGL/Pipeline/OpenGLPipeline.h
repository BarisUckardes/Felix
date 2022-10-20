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
	public:
		OpenGLPipeline(const PipelineCreateDesc& desc);
		virtual ~OpenGLPipeline() override;

		FORCEINLINE unsigned int GetGLProgramHandle() const noexcept { return _programHandle; }
		FORCEINLINE unsigned int GetGLPrimitives() const noexcept { return _primitives; }
		FORCEINLINE unsigned int GetGLFrontFace() const noexcept { return _frontFace; }
		FORCEINLINE unsigned int GetGLCullFace() const noexcept { return _cullFace; }
		FORCEINLINE unsigned int GetGLDepthFunction() const noexcept { return _depthFunction; }
		FORCEINLINE unsigned int GetGLShadingMode() const noexcept { return _shadingMode; }
		FORCEINLINE StencilGLFaceDesc GetGLStencilFrontDesc() const noexcept { return _stencilFrontFace; }
		FORCEINLINE StencilGLFaceDesc GetGLStencilBackDesc() const noexcept { return _stencilBackFace; }
	private:
		unsigned int _programHandle;
		unsigned int _primitives;
		unsigned int _frontFace;
		unsigned int _cullFace;
		unsigned int _depthFunction;
		unsigned int _shadingMode;
		StencilGLFaceDesc _stencilFrontFace;
		StencilGLFaceDesc _stencilBackFace;
	};
}