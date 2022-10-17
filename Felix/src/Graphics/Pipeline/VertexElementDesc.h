#pragma once
#include <Core/Core.h>
#include <Graphics/Pipeline/VertexElementDataType.h>
#include <string>

namespace Felix
{
	/// <summary>
	/// Required information to specify a vertex element
	/// </summary>
	struct EXPORT VertexElementDesc
	{
		std::string Name;
		VertexElementDataType DataType;
		bool bNormalize;
	};
}