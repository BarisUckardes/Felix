#include "WindowDeviceAdapter.h"
#include <Graphics/Device/GraphicsDevice.h>
#include <Window/Window.h>


namespace Felix
{
	void WindowDeviceAdapter::BindWindowDevice(Window* pWindow, GraphicsDevice* pDevice)
	{
		/*
		* Validate if the window expects the graphics device
		*/
		ASSERT(pDevice->GetOwnerWindow() == pWindow,"WindowDeviceAdapter","Cannot bind graphics device and window, window doesnt expect the target graphics device!");

		pWindow->_BindChildDevice(pDevice);
	}
}