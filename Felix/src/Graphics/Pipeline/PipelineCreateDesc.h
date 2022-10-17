#pragma once
#include <Graphics/Pipeline/DepthStencilStateDesc.h>
#include <Graphics/Pipeline/RasterizerStateDesc.h>
#include <Graphics/Pipeline/BlendingStateCreateDesc.h>
#include <Graphics/Pipeline/ResourceStateDesc.h>
#include <Graphics/Pipeline/ShaderPassDesc.h>
#include <Graphics/Pipeline/VertexLayoutDesc.h>
#include <Graphics/Pipeline/OutputDesc.h>
#include <Graphics/Pipeline/PipelineType.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a pipeline
	/// </summary>
	struct EXPORT PipelineCreateDesc
	{
		RasterizerStateDesc RasterizerDesc;
		DepthStencilStateDesc DepthStencilDesc;
		BlendingStateCreateDesc BlendingDesc;
		VertexLayoutDesc InputLayoutDesc;
		ShadingPassDesc ShadingPass;
		OutputDesc OutputDesc;
		PipelineType Type;
	};
}