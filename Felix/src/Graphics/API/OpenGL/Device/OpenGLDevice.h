#pragma once
#include <Graphics/Device/GraphicsDevice.h>

#ifdef FELIX_OS_WINDOWS
#include <Windows.h>
#endif

namespace Felix
{
	class EXPORT OpenGLDevice : public GraphicsDevice
	{
	public:
		OpenGLDevice(Window* pOwnerWindow);
		virtual ~OpenGLDevice() override;

	protected:
		virtual void SwapbuffersCore() override;
		virtual CommandBuffer* CreateCommandBufferCore(const CommandBufferCreateDesc& desc) override;
	private:

#ifdef FELIX_OS_WINDOWS
		HGLRC _context;
		HDC _windowDeviceContext;
#endif

	};
}