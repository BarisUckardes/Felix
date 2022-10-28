#include "DX12Device.h"
#include <Graphics/API/Directx12/Device/DX12DeviceObjects.h>

namespace Felix
{
	DX12Device::DX12Device(const StandaloneGraphicsDeviceCreateDesc& desc) 
	{
		_CreateDevice();
	}
	DX12Device::DX12Device(const WindowGraphicsDeviceCreateDesc& desc, Window* pOwnerWindow) : GraphicsDevice(pOwnerWindow)
	{
		_CreateDevice();
	}
	DX12Device::~DX12Device()
	{

	}
	std::string GetLastErrorAsString()
	{
		//Get the error message ID, if any.
		DWORD errorMessageID = ::GetLastError();
		if (errorMessageID == 0) {
			return std::string(); //No error message has been recorded
		}

		LPSTR messageBuffer = nullptr;

		//Ask Win32 to give us the string version of that message ID.
		//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

		//Copy the error message into a std::string.
		std::string message(messageBuffer, size);

		//Free the Win32's string's buffer.
		LocalFree(messageBuffer);

		return message;
	}
	void DX12Device::_CreateDevice()
	{
		/*
		* Collect factory flags and create dxgi factory
		*/
		unsigned int factoryFlags = 0;

#ifdef FELIX_DEBUG
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&_debugLayer))))
		{
			_debugLayer->EnableDebugLayer();

			factoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
		}
#endif

		ASSERT(SUCCEEDED(CreateDXGIFactory2(factoryFlags, IID_PPV_ARGS(_factory.GetAddressOf()))), "DX12Device", "Failed to create a factory");

		/*
		* Try select a viable gpu
		*/
		IDXGIAdapter1* pAdapter;
		int adapterIndex = 0;
		bool adapterFound = false;
		while (_factory->EnumAdapters1(adapterIndex, &pAdapter) != DXGI_ERROR_NOT_FOUND)
		{
			DXGI_ADAPTER_DESC1 desc = {};
			pAdapter->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				adapterIndex++;
				continue;
			}

			if (SUCCEEDED(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(_device.GetAddressOf()))))
			{
				adapterFound = true;
				break;
			}

			adapterIndex++;
		}

		ASSERT(adapterFound, "DX12Device", "Failed to create a viable GPU");

		/*
		* Create command queue
		*/
		D3D12_COMMAND_QUEUE_DESC cmdQueueDesc = {};
		ASSERT(SUCCEEDED(_device->CreateCommandQueue(&cmdQueueDesc, IID_PPV_ARGS(_cmdQueue.GetAddressOf()))), "DX12Device", "Failed to create a command queue");

		/*
		* Create command allocator
		*/
		ASSERT(SUCCEEDED(_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(_cmdAllocator.GetAddressOf()))), "DX12Device", "Failed to create a command allocator");

		/*
		* Create fence
		*/
		_device->CreateFence(1, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&_fence));

		_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

	}
	void DX12Device::SwapbuffersCore()
	{
		const DX12SwapchainFramebuffer* pFramebuffer = (const DX12SwapchainFramebuffer*)GetSwapchainFramebuffer();

		ASSERT(pFramebuffer->GetDXSwapchain()->Present(1, 0), "DX12Device", "Failed to swap the swapchain buffers");
	}
	CommandBuffer* DX12Device::CreateCommandBufferCore(const CommandBufferCreateDesc& desc)
	{
		return new DX12CommandBuffer(desc,this);
	}
	GraphicsBuffer* DX12Device::CreateBufferCore(const GraphicsBufferCreateDesc& desc)
	{
		return nullptr;
	}
	Shader* DX12Device::CreateShaderCore(const ShaderCreateDesc& desc)
	{
		return nullptr;
	}
	Texture* DX12Device::CreateTextureCore(const TextureCreateDesc& desc)
	{
		return nullptr;
	}
	Framebuffer* DX12Device::CreateFramebufferCore(const FramebufferCreateDesc& desc)
	{
		return nullptr;
	}
	Framebuffer* DX12Device::CreateSwapchainFramebufferCore(const SwapchainFramebufferCreateDesc& desc)
	{
		return new DX12SwapchainFramebuffer(desc,GetOwnerWindow(),this);
	}
	GraphicsResource* DX12Device::CreateResourceCore(const GraphicsResourceCreateDesc& desc)
	{
		return nullptr;
	}
	Pipeline* DX12Device::CreatePipelineCore(const PipelineCreateDesc& desc)
	{
		return nullptr;
	}
	TextureSampler* DX12Device::CreateTextureSamplerCore(const TextureSamplerCreateDesc& desc)
	{
		return nullptr;
	}
	void DX12Device::UpdateBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferUpdateDesc& desc)
	{

	}
	void DX12Device::UpdateTextureCore(Texture* pTexture, const TextureUpdateDesc& desc)
	{

	}

	void DX12Device::WaitForFinishCore()
	{
		const unsigned int fenceValue = _fenceValue;
		_cmdQueue->Signal(_fence.Get(), fenceValue);

		_fenceValue++;

		if (_fence->GetCompletedValue() < _fenceValue)
		{
			_fence->SetEventOnCompletion(fenceValue, _fenceEvent);

			WaitForSingleObject(_fenceEvent, INFINITE);
		}

		ASSERT(SUCCEEDED(_cmdAllocator.Reset()),"DX12Device","Couldnt reset the command allocator");

	}
	void DX12Device::SubmitCommandsCore(CommandBuffer* pCmdBuffer)
	{
		const DX12CommandBuffer* pDX12CmdBuffer = (const DX12CommandBuffer*)pCmdBuffer;

		ID3D12CommandList* pCmdList = pDX12CmdBuffer->GetDXCmdList();

		_cmdQueue->ExecuteCommandLists(1, &pCmdList);
	}
}