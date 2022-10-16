#pragma once
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Framebuffer/FramebufferCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// Graphics framebuffer which authored by a Graphics Device
	/// It contains drawable render target textures which user can render their stuff into with shaders
	/// </summary>
	class EXPORT Framebuffer : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE std::vector<Texture*> GetAttachments() const noexcept { return _attachments; }
		FORCEINLINE Texture* GetDepthStencilAttachment() const noexcept { return _depthStencilTexture; }
		FORCEINLINE unsigned int GetWidth() const noexcept { return _width; }
		FORCEINLINE unsigned int GetHeight() const noexcept { return _height; }
		FORCEINLINE bool HasDepthStencil() const noexcept { return _depthStencil; }
		FORCEINLINE bool IsSwapchain() const noexcept { return _swapchain; }

		FORCEINLINE GraphicsDeviceObjectType GetDeviceObjectType() const noexcept final { return GraphicsDeviceObjectType::Framebuffer; }
	protected:
		Framebuffer(const FramebufferCreateDesc& desc);
		virtual ~Framebuffer(){}

	private:
		std::vector<Texture*> _attachments;
		Texture* _depthStencilTexture;
		unsigned int _width;
		unsigned int _height;
		bool _depthStencil;
		bool _swapchain;
	};
}