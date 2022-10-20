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
		OpenGLPipeline(const PipelineCreateDesc& desc);
		virtual ~OpenGLPipeline() override;

		FORCEINLINE unsigned int GetGLProgramHandle() const noexcept { return _programHandle; }
		FORCEINLINE unsigned int GetGLPrimitives() const noexcept { return _primitives; }
		FORCEINLINE unsigned int GetGLFrontFace() const noexcept { return _frontFace; }
		FORCEINLINE unsigned int GetGLCullFace() const noexcept { return _cullFace; }
		FORCEINLINE unsigned int GetGLDepthFunction() const noexcept { return _depthFunction; }
		FORCEINLINE unsigned int GetGLShadingMode() const noexcept { return _shadingMode; }
	private:
		unsigned int _programHandle;
		unsigned int _primitives;
		unsigned int _frontFace;
		unsigned int _cullFace;
		unsigned int _depthFunction;
		unsigned int _shadingMode;

	};
}