#pragma once
#include <Graphics/Shader/ShaderType.h>
#include <string>

namespace Felix
{
	/// <summary>
	/// Required information to create a shader
	/// </summary>
	struct EXPORT ShaderCreateDesc
	{
		ShaderType Type;
		std::string Source;
		std::string EntryPoint;
	};
}