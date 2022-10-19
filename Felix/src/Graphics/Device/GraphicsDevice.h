#pragma once
#include <Core/Core.h>
#include <Graphics/Device/GraphicsDeviceCapabilities.h>
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/Device/WindowGraphicsDeviceCreateDesc.h>
#include <Graphics/Framebuffer/SwapchainFramebufferCreateDesc.h>
#include <vector>

namespace Felix
{
	class GraphicsDeviceObject;
	class Window;

	class CommandBuffer;
	struct CommandBufferCreateDesc;

	class GraphicsBuffer;
	struct GraphicsBufferCreateDesc;
	struct GraphicsBufferUpdateDesc;

	class Texture;
	struct TextureCreateDesc;
	struct TextureUpdateDesc;

	class Framebuffer;
	class SwapchainFramebuffer;
	struct FramebufferCreateDesc;
	struct SwapchainFramebufferCreateDesc;

	class GraphicsResource;
	struct GraphicsResourceCreateDesc;

	class Pipeline;
	struct PipelineCreateDesc;

	class Shader;
	struct ShaderCreateDesc;

	class EXPORT GraphicsDevice
	{
	public:
		static GraphicsDevice* CreateStandalone(const StandaloneGraphicsDeviceCreateDesc& desc,const GraphicsDeviceCapabilities& requiredCapabilities = {});
		static GraphicsDevice* CreateWindowDevice(const WindowGraphicsDeviceCreateDesc& desc, const SwapchainFramebufferCreateDesc& swapchainDesc,Window* pOwnerWindow,const GraphicsDeviceCapabilities& requiredCapabilities = {});
	public:
		FORCEINLINE Window* GetOwnerWindow() const noexcept { return _ownerWindow; }
		FORCEINLINE bool IsStandalone() const noexcept { return _standalone; }
		FORCEINLINE GraphicsDeviceCapabilities GetCapabilities() const noexcept { return _capabilities; }
		FORCEINLINE Framebuffer* GetSwapchainFramebuffer() const noexcept { return _swapchainFramebuffer; }

		void Swapbuffers();

		CommandBuffer* CreateCommandBuffer(const CommandBufferCreateDesc& desc);
		GraphicsBuffer* CreateBuffer(const GraphicsBufferCreateDesc& desc);
		Shader* CreateShader(const ShaderCreateDesc& desc);
		Texture* CreateTexture(const TextureCreateDesc& desc);
		Framebuffer* CreateFramebuffer(const FramebufferCreateDesc& desc);
		GraphicsResource* CreateResource(const GraphicsResourceCreateDesc& desc);
		virtual Pipeline* CreatePipeline(const PipelineCreateDesc& desc);

		void UpdateBuffer(GraphicsBuffer* pBuffer,const GraphicsBufferUpdateDesc& desc);
		void UpdateTexture(Texture* pTexture,const TextureUpdateDesc& desc);

	protected:
		GraphicsDevice(Window* pOwnerWindow);
		GraphicsDevice();
		virtual ~GraphicsDevice() {};

		void SetCapabilities(const GraphicsDeviceCapabilities& capabilities) { _capabilities = capabilities; }

		virtual void SwapbuffersCore() = 0;

		virtual CommandBuffer* CreateCommandBufferCore(const CommandBufferCreateDesc& desc) = 0;
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferCreateDesc& desc) = 0;
		virtual Shader* CreateShaderCore(const ShaderCreateDesc& desc) = 0;
		virtual Texture* CreateTextureCore(const TextureCreateDesc& desc) = 0;
		virtual Framebuffer* CreateFramebufferCore(const FramebufferCreateDesc& desc) = 0;
		virtual Framebuffer* CreateSwapchainFramebufferCore(const SwapchainFramebufferCreateDesc& desc) = 0;
		virtual GraphicsResource* CreateResourceCore(const GraphicsResourceCreateDesc& desc) = 0;
		virtual Pipeline* CreatePipelineCore(const PipelineCreateDesc& desc) = 0;

		virtual void UpdateBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferUpdateDesc& desc) = 0;
		virtual void UpdateTextureCore(Texture* pTexture, const TextureUpdateDesc& desc) = 0;

	private:
		void RegisterDeviceObject(GraphicsDeviceObject* pDeviceObject);
		void CreateSwapchainFramebuffer(const SwapchainFramebufferCreateDesc& desc);
	private:
		std::vector<GraphicsDeviceObject*> _objects;
		Window* _ownerWindow;
		Framebuffer* _swapchainFramebuffer;
		GraphicsDeviceCapabilities _capabilities;
		bool _standalone;
	};
}