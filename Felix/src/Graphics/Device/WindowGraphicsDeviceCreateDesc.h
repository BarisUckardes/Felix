#pragma once
#include <Core/Core.h>
#include <Graphics/GraphicsAPI.h>
#include <Graphics/Texture/TextureFormat.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a graphics device whics is owned by a window
	/// </summary>
	struct EXPORT WindowGraphicsDeviceCreateDesc
	{
		GraphicsAPI PreferredAPI;
		TextureFormat SwapchainBufferFormat;
		unsigned char SwapchainBufferCount;
		TextureFormat SwapchainDepthStencilBufferFormat;
	};
}