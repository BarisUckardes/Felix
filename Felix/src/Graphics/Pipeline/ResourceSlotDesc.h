#pragma once
#include <string>
#include <Graphics/Resource/GraphicsResourceType.h>
#include <Graphics/Shader/ShaderType.h>

namespace Felix
{
	/// <summary>
	/// Required information to describe a resource slot
	/// </summary>
	struct EXPORT ResourceSlotDesc
	{
		std::string Name;
		GraphicsResourceType Type;
		ShaderType Stage;
	};
}