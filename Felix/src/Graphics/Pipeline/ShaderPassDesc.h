#pragma once
#include <Core/Core.h>
#include <vector>

namespace Felix
{
	class Shader;

	/// <summary>
	/// Required information to describe the pipeline's shaders
	/// </summary>
	struct EXPORT ShadingPassDesc
	{
		std::vector<Shader*> Shaders;
	};
}