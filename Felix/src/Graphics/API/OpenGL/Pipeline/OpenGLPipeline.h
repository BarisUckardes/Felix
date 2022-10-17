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
	private:
		unsigned int _programHandle;

	};
}