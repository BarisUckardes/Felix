#pragma once
#include <Core/Core.h>
#include <Graphics/Pipeline/DepthFunction.h>
#include <Graphics/Pipeline/StencilFaceDesc.h>

namespace Felix
{
	struct EXPORT DepthStencilStateDesc
	{
		DepthFunction TestFunction;
		bool bEnableDepthTest;
		bool bEnableDeptWrite;
		bool bEnableStencilTest;
		StencilFaceDesc StencilFrontFace;
		StencilFaceDesc StencilBackFace;
	};
}