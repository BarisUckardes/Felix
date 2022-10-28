#pragma once
#include <Graphics/Texture/TextureType.h>
#include <Graphics/Texture/TextureFormat.h>
#include <dxgi.h>

namespace Felix
{
	class EXPORT DXGIUtils
	{
	public:
		DXGIUtils() = delete;
		~DXGIUtils() = delete;

		FORCEINLINE static DXGI_FORMAT GetFormat(const TextureFormat format);
	};
}