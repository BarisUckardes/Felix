#pragma once
#include <Graphics/Pipeline/CullMode.h>
#include <Graphics/Pipeline/FrontFaceMode.h>
#include <Graphics/Pipeline/PolygonShadingMode.h>
#include <Graphics/Pipeline/PrimitiveTopology.h>

namespace Felix
{
	/// <summary>
	/// Required information for creating a pipeline rasterizer state
	/// </summary>
	struct EXPORT RasterizerStateDesc
	{
		FrontFaceMode FrontFace;
		CullMode CulledFace;
		PolygonShadingMode ShadingMode;
		bool bEnableDepthClip;
		bool bEnableScissorTest;
	};
}
