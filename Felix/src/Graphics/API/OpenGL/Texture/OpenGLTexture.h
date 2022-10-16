#pragma once
#include <Graphics/Texture/Texture.h>
#include <Graphics/Texture/TextureCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// OpenGL texture implementation
	/// </summary>
	class EXPORT OpenGLTexture : public Texture
	{
	public:
		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }

	protected:
		OpenGLTexture(const TextureCreateDesc& desc);
		virtual ~OpenGLTexture();

	private:
		unsigned int _handle;
	};
}