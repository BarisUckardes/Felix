#include "DX12SwapchainFramebuffer.h"
#include <Platform/Windows/Window/WindowsWindow.h>
#include <Graphics/API/Directx12/Device/DX12Device.h>
#include <Graphics/API/Directx/DXGI/DXGIUtils.h>

namespace Felix
{
	DX12SwapchainFramebuffer::DX12SwapchainFramebuffer(const SwapchainFramebufferCreateDesc& swapchainDesc, Window* pOwnerWindow,DX12Device* pDevice) : SwapchainFramebuffer(swapchainDesc,pOwnerWindow)
	{

		/*
		* Create swapchain
		*/
		WindowsWindow* pWin32Window = (WindowsWindow*)pOwnerWindow;

		IDXGIFactory4* pFactory = pDevice->GetDXFactory();
		ID3D12CommandQueue* pCmdQueue = nullptr;
		ID3D12Device* pDX12Device = (ID3D12Device*)pDevice->GetDXDevice();

		DXGI_MODE_DESC bufferDesc = {};
		bufferDesc.Width = swapchainDesc.Width;
		bufferDesc.Height = swapchainDesc.Height;
		bufferDesc.Format = DXGIUtils::GetFormat(swapchainDesc.Format);

		DXGI_SAMPLE_DESC sampleDesc = {};
		sampleDesc.Count = 1;
		sampleDesc.Quality = 0;

		const unsigned int bufferCount = swapchainDesc.BufferCount;
		DXGI_SWAP_CHAIN_DESC desc = {};
		desc.BufferCount = bufferCount;
		desc.BufferDesc = bufferDesc;
		desc.Windowed = true;
		desc.SampleDesc = sampleDesc;
		desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		desc.OutputWindow = pWin32Window->GetWin32WindowHandle();


		ASSERT(SUCCEEDED(pFactory->CreateSwapChain(pDevice->GetDXCmdQueue(), &desc, (IDXGISwapChain**)_swapchain.GetAddressOf())), "DX12SwapchainFramebuffer", "Failed to create swapchain");

		/*
		* Make association
		*/
		ASSERT(SUCCEEDED(pFactory->MakeWindowAssociation(pWin32Window->GetWin32WindowHandle(), DXGI_MWA_NO_ALT_ENTER)), "DX12SwapchainFramebuffer", "Failed to associate with the window");

		/*
		* Create swapchain descriptor heap
		*/
		D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
		rtvHeapDesc.NumDescriptors = swapchainDesc.BufferCount;
		rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

		ASSERT(SUCCEEDED(pDX12Device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&_rtvHeap))), "DX12SwapchainFramebuffer", "Failed to create descriptor heap for the swapchain rtvs");

		const unsigned int rtvDescriptorSize = pDX12Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

		D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = _rtvHeap->GetCPUDescriptorHandleForHeapStart();

		for (unsigned char i = 0; i < desc.BufferCount; i++)
		{
			DXPTR<ID3D12Resource> rtv;

			ASSERT(SUCCEEDED(_swapchain->GetBuffer(i, IID_PPV_ARGS(&rtv))), "DX12SwapchainFramebuffer", "Get swapchain back buffer failed!");

			pDX12Device->CreateRenderTargetView(rtv.Get(), nullptr, rtvHandle);

			rtvHandle.ptr += rtvDescriptorSize;

			_rtvs.push_back(rtv);
		}

	}
	DX12SwapchainFramebuffer::~DX12SwapchainFramebuffer()
	{

	}
	D3D12_CPU_DESCRIPTOR_HANDLE DX12SwapchainFramebuffer::GetDXCurrentRtvDescriptor() const noexcept
	{
		ID3D12Device* pDX12Device = ((DX12Device*)GetOwnerDevice())->GetDXDevice();
		const unsigned int rtvDescriptorSize = pDX12Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
		D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = _rtvHeap->GetCPUDescriptorHandleForHeapStart();
		rtvHandle.ptr += rtvDescriptorSize*_swapchain->GetCurrentBackBufferIndex();

		return rtvHandle;
	}
	void DX12SwapchainFramebuffer::OnResizeCore(const unsigned int width, const unsigned int Height)
	{

	}
}