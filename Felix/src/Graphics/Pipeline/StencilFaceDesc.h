#pragma once
#include <Graphics/Pipeline/StencilFunction.h>
#include <Graphics/Pipeline/StencilOperation.h>

namespace Felix
{
	/// <summary>
	/// Single stencil 
	/// </summary>
	struct EXPORT StencilFaceDesc
	{
		int StencilReferenceValue;
		int StencilWriteMask;
		unsigned int StencilReadMask;
		StencilFunction Function;
		StencilOperation FailOperation;
		StencilOperation PassOperation;
		StencilOperation DepthFailOperation;
	};
}