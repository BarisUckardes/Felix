#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported shaders
	/// </summary>
	enum class EXPORT ShaderType
	{
		Vertex,
		Fragment,
		Geometry,
		TesellationEval,
		TesellationControl,
		Compute
	};
}