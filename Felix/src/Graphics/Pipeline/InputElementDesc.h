#pragma once
#include <Core/Core.h>
#include <Graphics/Pipeline/InputElementDataType.h>
#include <Graphics/Pipeline/InputElementSemantic.h>
#include <string>

namespace Felix
{
	/// <summary>
	/// Required information to specify a vertex element
	/// </summary>
	struct EXPORT InputElementDesc
	{
		InputElementDesc(const std::string& name,const InputElementSemantic semantic,const InputElementDataType dataType,const bool normalize) : Name(name),Semantic(semantic),DataType(dataType),bNormalize(normalize) {}

		std::string Name;
        InputElementSemantic Semantic;
		InputElementDataType DataType;
		bool bNormalize;
	};
}