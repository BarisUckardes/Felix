#pragma once
#include <Graphics/Resource/GraphicsResourceType.h>

namespace Felix
{
	class GraphicsDeviceObject;

	/// <summary>
	/// Required information to create a graphics resource
	/// </summary>
	struct EXPORT GraphicsResourceCreateDesc
	{
		GraphicsResourceType Type;
		GraphicsDeviceObject* pDeviceObject;
	};
}