#pragma once
#include <Core/Core.h>
#include <Graphics/Texture/TextureFormat.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a swapchain framebuffer
	/// </summary>
	struct EXPORT SwapchainFramebufferCreateDesc
	{
		TextureFormat Format;
		TextureFormat DepthStencilFormat;
		unsigned int Width;
		unsigned int Height;
		unsigned char BufferCount;
	};
}