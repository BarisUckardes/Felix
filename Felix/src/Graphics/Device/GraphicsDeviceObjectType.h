#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Existing graphics device object types
	/// </summary>
	enum class EXPORT GraphicsDeviceObjectType
	{
		Texture = 0,
		TextureSampler,
		Buffer,
		Shader,
		Framebuffer,
		Resource,
		CommandBuffer,
		Pipeline
	};
}