#pragma once
#include <Core/Core.h>

namespace Felix
{
	struct EXPORT GraphicsDeviceCapabilities
	{
		GraphicsDeviceCapabilities() : Any(true) {}

		bool Any;

		bool HardwareRaytracingSupport;
		bool GeometryShaderSupport;
		bool ComputeShaderSupport;
	};
}