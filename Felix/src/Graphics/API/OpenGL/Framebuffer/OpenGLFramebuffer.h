#pragma once
#include <Graphics/Framebuffer/Framebuffer.h>

namespace Felix
{
	class EXPORT OpenGLFramebuffer : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferCreateDesc& desc, const bool bSwapchain);
		virtual ~OpenGLFramebuffer();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		unsigned int _handle;
	};
}