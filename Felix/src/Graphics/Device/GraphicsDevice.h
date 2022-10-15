#pragma once
#include <Core/Core.h>
#include <Graphics/Device/GraphicsDeviceCapabilities.h>
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/Device/WindowGraphicsDeviceCreateDesc.h>
namespace Felix
{
	class Window;

	class EXPORT GraphicsDevice
	{
	public:
		static GraphicsDevice* CreateStandalone(const StandaloneGraphicsDeviceCreateDesc& desc,const GraphicsDeviceCapabilities& requiredCapabilities = {});
		static GraphicsDevice* CreateWindowDevice(const WindowGraphicsDeviceCreateDesc& desc,Window* pOwnerWindow,const GraphicsDeviceCapabilities& requiredCapabilities = {});
	public:
		FORCEINLINE Window* GetOwnerWindow() const noexcept { return _ownerWindow; }
		FORCEINLINE bool IsStandalone() const noexcept { return _standalone; }

		void Swapbuffers();

	protected:
		GraphicsDevice(Window* pOwnerWindow);
		GraphicsDevice();
		virtual ~GraphicsDevice() {};

		virtual void SwapbuffersCore() = 0;
	private:
		Window* _ownerWindow;
		GraphicsDeviceCapabilities _capabilities;
		bool _standalone;
	};
}