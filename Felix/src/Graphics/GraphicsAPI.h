#pragma once

namespace Felix
{
	/// <summary>
	/// Supported graphics apis
	/// </summary>
	enum class GraphicsAPI
	{
		OpenGL,
		OpenGLES,
		Directx11,
		Directx12,
		Vulkan,
		Metal,
		GNM,
		GNMX
	};
}