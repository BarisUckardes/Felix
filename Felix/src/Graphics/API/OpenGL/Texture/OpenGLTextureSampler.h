#pragma once
#include <Graphics/Texture/TextureSampler.h>

namespace Felix
{
	class EXPORT OpenGLTextureSampler : public TextureSampler
	{
	public:
		OpenGLTextureSampler(const TextureSamplerCreateDesc& desc);
		virtual ~OpenGLTextureSampler();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }

	private:
		unsigned int _handle;
	};
}