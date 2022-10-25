#pragma once
#include <Graphics/Framebuffer/Framebuffer.h>
#include <Graphics/Framebuffer/FramebufferCreateDesc.h>
#include <Graphics/Framebuffer/SwapchainFramebufferCreateDesc.h>

namespace Felix
{
	class Window;

	/// <summary>
	/// Represents the swapchain framebuffer authored by the graphics device
	/// </summary>
	class EXPORT SwapchainFramebuffer : public Framebuffer
	{
		friend class Window;
	public:

		FORCEINLINE Window* GetOwnerWindow() const noexcept { return _ownerWindow; }
		FORCEINLINE TextureFormat GetColorFormat() const noexcept { return _colorFormat; }
		FORCEINLINE TextureFormat GetDepthStencilFormat() const noexcept { return _depthStencilFormat; }
		FORCEINLINE unsigned int GetBufferCount() const noexcept { return _bufferCount; }


	protected:
		SwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc, Window* pOwnerWindow) : Framebuffer({{},swapchainDesc.Width,swapchainDesc.Height},true),
			_ownerWindow(pOwnerWindow), _colorFormat(swapchainDesc.Format), _depthStencilFormat(swapchainDesc.DepthStencilFormat), _bufferCount(swapchainDesc.BufferCount)
		{

		}

		virtual ~SwapchainFramebuffer() override {}

		virtual void OnResizeCore(const unsigned int width, const unsigned int Height) = 0;

	private:
		 void OnResize(const unsigned int width, const unsigned int height);
	private:
		Window* _ownerWindow;
		TextureFormat _colorFormat;
		TextureFormat _depthStencilFormat;
		unsigned int _bufferCount;
	};
}