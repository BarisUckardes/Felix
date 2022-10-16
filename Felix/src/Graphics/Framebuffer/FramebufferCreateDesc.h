#pragma once
#include <Graphics/Framebuffer/FramebufferAttachmentDesc.h>
#include <vector>

namespace Felix
{
	/// <summary>
	/// Required information to create a framebuffer
	/// </summary>
	struct EXPORT FramebufferCreateDesc
	{
		std::vector<Texture*> Attachments;
		unsigned int Width;
		unsigned int Height;
	};
}