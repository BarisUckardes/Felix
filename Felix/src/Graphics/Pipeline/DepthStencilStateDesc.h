#pragma once
#include <Core/Core.h>
#include <Graphics/Pipeline/DepthTestFunction.h>
#include <Graphics/Pipeline/StencilFaceDesc.h>

namespace Felix
{
	struct EXPORT DepthStencilStateDesc
	{
		DepthTestFunction TestFunction;
		bool bEnableDepthTest;
		bool bEnableDeptWrite;
		bool bEnableStencilTest;
		StencilFaceDesc StencilFrontFace;
		StencilFaceDesc StencilBackFace;
	};
}