#pragma once
#include <Graphics/Pipeline/BlendingFunction.h>
#include <Graphics/Pipeline/BlendingType.h>

namespace Felix
{
	/// <summary>
	/// Required information to create the blending state of the pipeline
	/// </summary>
	struct EXPORT BlendingStateDesc
	{
		BlendingFactor SourceColorFactor;
		BlendingFactor DestinationColorFactor;
		BlendingFunction ColorFunction;

		BlendingFactor SourceAlphaFactor;
		BlendingFactor DestinationAlphaFactor;
		BlendingFunction AlphaFunction;
	};
}