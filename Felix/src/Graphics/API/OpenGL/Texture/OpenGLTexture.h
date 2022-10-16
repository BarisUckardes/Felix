#pragma once
#include <Graphics/Texture/Texture.h>
#include <Graphics/Texture/TextureCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// OpenGL texture implementation
	/// </summary>
	class EXPORT OpenGLTexture final : public Texture
	{
	public:
		OpenGLTexture(const TextureCreateDesc& desc);
		virtual ~OpenGLTexture();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		unsigned int _handle;
	};
}