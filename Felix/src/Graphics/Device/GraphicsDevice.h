#pragma once
#include <Core/Core.h>
#include <Graphics/Device/GraphicsDeviceCapabilities.h>
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/Device/WindowGraphicsDeviceCreateDesc.h>
#include <vector>

namespace Felix
{
	class GraphicsDeviceObject;
	class Window;
	class CommandBuffer;
	struct CommandBufferCreateDesc;

	class EXPORT GraphicsDevice
	{
	public:
		static GraphicsDevice* CreateStandalone(const StandaloneGraphicsDeviceCreateDesc& desc,const GraphicsDeviceCapabilities& requiredCapabilities = {});
		static GraphicsDevice* CreateWindowDevice(const WindowGraphicsDeviceCreateDesc& desc,Window* pOwnerWindow,const GraphicsDeviceCapabilities& requiredCapabilities = {});
	public:
		FORCEINLINE Window* GetOwnerWindow() const noexcept { return _ownerWindow; }
		FORCEINLINE bool IsStandalone() const noexcept { return _standalone; }
		FORCEINLINE GraphicsDeviceCapabilities GetCapabilities() const noexcept { return _capabilities; }

		void Swapbuffers();

		CommandBuffer* CreateCommandBuffer(const CommandBufferCreateDesc& desc);

	protected:
		GraphicsDevice(Window* pOwnerWindow);
		GraphicsDevice();
		virtual ~GraphicsDevice() {};

		void SetCapabilities(const GraphicsDeviceCapabilities& capabilities);

		virtual void SwapbuffersCore() = 0;

		FORCEINLINE virtual CommandBuffer* CreateCommandBufferCore(const CommandBufferCreateDesc& desc) = 0;

	private:
		void RegisterDeviceObject(GraphicsDeviceObject* pDeviceObject);
	private:
		std::vector<GraphicsDeviceObject*> _objects;
		Window* _ownerWindow;
		GraphicsDeviceCapabilities _capabilities;
		bool _standalone;
	};
}