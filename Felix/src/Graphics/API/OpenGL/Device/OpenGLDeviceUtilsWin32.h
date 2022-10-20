#pragma once
#include <Core/Core.h>
#include <Graphics/Texture/TextureFormat.h>

namespace Felix
{
	class EXPORT OpenGLDeviceUtilsWin32
	{
	public:
		OpenGLDeviceUtilsWin32() = delete;
		~OpenGLDeviceUtilsWin32() = delete;

		FORCEINLINE static unsigned int GetColorBits(const TextureFormat format) noexcept;
		FORCEINLINE static unsigned int GetAlphaBits(const TextureFormat format) noexcept;
		FORCEINLINE static unsigned int GetDepthBits(const TextureFormat format) noexcept;
		FORCEINLINE static unsigned int GetStencilBits(const TextureFormat format) noexcept;
	};
}