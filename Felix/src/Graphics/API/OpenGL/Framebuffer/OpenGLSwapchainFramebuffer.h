#pragma once
#include <Graphics/Framebuffer/SwapchainFramebuffer.h>

namespace Felix
{
	class EXPORT OpenGLSwapchainFramebuffer final : public SwapchainFramebuffer
	{
	public:
		OpenGLSwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc,const FramebufferCreateDesc& framebufferDesc,Window* pOwnerWindow);
		virtual ~OpenGLSwapchainFramebuffer();

	protected:
		virtual void OnResizeCore(const unsigned int width, const unsigned int Height) override;
	private:

	};
}