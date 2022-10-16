#pragma once
#include <Core/Core.h>
#include <Graphics/Framebuffer/FramebufferCreateDesc.h>


namespace Felix
{
	class EXPORT OpenGLFramebufferUtils
	{
	public:
		OpenGLFramebufferUtils() = delete;
		~OpenGLFramebufferUtils() = delete;


		FORCEINLINE static unsigned int GetFramebuffer() noexcept { return 0; }
	};
}