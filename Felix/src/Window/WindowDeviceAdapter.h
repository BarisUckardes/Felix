#pragma once
#include <Core/Core.h>

namespace Felix
{
	class Window;
	class GraphicsDevice;

	class EXPORT WindowDeviceAdapter
	{
	public:
		WindowDeviceAdapter() = delete;
		~WindowDeviceAdapter() = delete;

		static void BindWindowDevice(Window* pWindow, GraphicsDevice* pDevice);
	};
}