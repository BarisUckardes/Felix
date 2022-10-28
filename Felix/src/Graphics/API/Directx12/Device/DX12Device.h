#pragma once
#include <Graphics/Device/GraphicsDevice.h>
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/API/Directx12/Core/DX12Core.h>
#include <dxgi.h>
#include <dxgi1_4.h>

namespace Felix
{
	class EXPORT DX12Device : public GraphicsDevice
	{
	public:
		DX12Device(const StandaloneGraphicsDeviceCreateDesc& desc);
		DX12Device(const WindowGraphicsDeviceCreateDesc& desc, Window* pOwnerWindow);
		virtual ~DX12Device() override;

		FORCEINLINE IDXGIFactory4* GetDXFactory() const noexcept { return _factory.Get();}
		FORCEINLINE ID3D12Device* GetDXDevice() const noexcept { return _device.Get(); }
		FORCEINLINE ID3D12CommandQueue* GetDXCmdQueue() const noexcept { return _cmdQueue.Get(); }
		FORCEINLINE ID3D12CommandAllocator* GetDXCmdAllocator() const noexcept { return _cmdAllocator.Get(); }
	protected:
		// Inherited via GraphicsDevice
		virtual void SwapbuffersCore() override;
		virtual CommandBuffer* CreateCommandBufferCore(const CommandBufferCreateDesc& desc) override;
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferCreateDesc& desc) override;
		virtual Shader* CreateShaderCore(const ShaderCreateDesc& desc) override;
		virtual Texture* CreateTextureCore(const TextureCreateDesc& desc) override;
		virtual Framebuffer* CreateFramebufferCore(const FramebufferCreateDesc& desc) override;
		virtual Framebuffer* CreateSwapchainFramebufferCore(const SwapchainFramebufferCreateDesc& desc) override;
		virtual GraphicsResource* CreateResourceCore(const GraphicsResourceCreateDesc& desc) override;
		virtual Pipeline* CreatePipelineCore(const PipelineCreateDesc& desc) override;
		virtual TextureSampler* CreateTextureSamplerCore(const TextureSamplerCreateDesc& desc) override;
		virtual void UpdateBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferUpdateDesc& desc) override;
		virtual void UpdateTextureCore(Texture* pTexture, const TextureUpdateDesc& desc) override;
		virtual void WaitForFinishCore() override final;
		virtual void SubmitCommandsCore(CommandBuffer* pCmdBuffer) override final;
	private:
		void _CreateDevice();
	private:
		DXPTR<IDXGIFactory4> _factory;
		DXPTR<ID3D12Device> _device;
		DXPTR<ID3D12CommandQueue> _cmdQueue;
		DXPTR<ID3D12CommandAllocator> _cmdAllocator;
		DXPTR<ID3D12Fence> _fence;
		HANDLE _fenceEvent;
		unsigned int _fenceValue;
#ifdef FELIX_DEBUG
		DXPTR<ID3D12Debug> _debugLayer;
#endif
	};
}