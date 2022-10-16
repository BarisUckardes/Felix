#pragma once
#include <Core/Core.h>

namespace Felix
{
	class Texture;

	/// <summary>
	/// Required information to describe an framebuffer attachment
	/// </summary>
	struct EXPORT FramebufferAttachmentDesc
	{
		Texture* pTexture;
	};
}