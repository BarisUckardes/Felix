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
		FORCEINLINE static unsigned int GetStencilOperation(const StencilOperation operation);
		FORCEINLINE static unsigned int GetStencilFunction(const StencilFunction function);
		FORCEINLINE static unsigned int GetBlendingFunction(const BlendingFunction function);
		FORCEINLINE static unsigned int GetBlendingColorFactor(const BlendingFactor factor);
		FORCEINLINE static unsigned int GetBlendingAlphaFactor(const BlendingFactor factor);
	};
}