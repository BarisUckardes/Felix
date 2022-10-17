#pragma once
#include <Core/Core.h>
#include <Graphics/Pipeline/InputElementDataType.h>
#include <string>

namespace Felix
{
	/// <summary>
	/// Required information to specify a vertex element
	/// </summary>
	struct EXPORT InputElementDesc
	{
		std::string Name;
		InputElementDataType DataType;
		bool bNormalize;
	};
}