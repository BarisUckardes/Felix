#pragma once
#include <Graphics/Framebuffer/SwapchainFramebuffer.h>
#include <Graphics/API/Directx12/Core/DX12Core.h>
#include <dxgi.h>
#include <dxgi1_4.h>

namespace Felix
{
	class EXPORT DX12SwapchainFramebuffer : public SwapchainFramebuffer
	{
	public:
		DX12SwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc, Window* pOwnerWindow,DX12Device* pDevice);
		virtual ~DX12SwapchainFramebuffer() override;

		FORCEINLINE IDXGISwapChain3* GetDXSwapchain() const noexcept { return _swapchain.Get(); }
		FORCEINLINE ID3D12DescriptorHeap* GetDXRtvHeap() const noexcept { return _rtvHeap.Get(); }
		FORCEINLINE D3D12_CPU_DESCRIPTOR_HANDLE GetDXCurrentRtvDescriptor() const noexcept;
		FORCEINLINE ID3D12Resource* GetDXCurrentRtv() const noexcept { return _rtvs[_swapchain->GetCurrentBackBufferIndex()].Get(); }

	protected:
		// Inherited via SwapchainFramebuffer
		virtual void OnResizeCore(const unsigned int width, const unsigned int Height) override;
	private:
		DXPTR<IDXGISwapChain3> _swapchain;
		DXPTR<ID3D12DescriptorHeap> _rtvHeap;
		std::vector<DXPTR<ID3D12Resource>> _rtvs;


	};
}