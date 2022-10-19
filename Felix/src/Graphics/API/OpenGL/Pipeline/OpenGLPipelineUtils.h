#pragma once
#include <Core/Core.h>
#include <Graphics/Pipeline/PipelineCreateDesc.h>

namespace Felix
{
	class EXPORT OpenGLPipelineUtils
	{
	public:
		OpenGLPipelineUtils() = delete;
		~OpenGLPipelineUtils() = delete;

		FORCEINLINE static unsigned int GetFrontFace(const FrontFaceMode frontFace);
		FORCEINLINE static unsigned int GetCullFace(const CullMode mode);
		FORCEINLINE static unsigned int GetDepthFunction(const DepthTestFunction function);
		FORCEINLINE static unsigned int GetPrimitiveTopology(const PrimitiveTopology topology);
		FORCEINLINE static unsigned int GetShadingMode(const PolygonShadingMode mode);
		FORCEINLINE static unsigned int GetInputElementComponentCount(const InputElementDataType type);
		FORCEINLINE static unsigned int GetInputElementDataType(const InputElementDataType type);
	};
}