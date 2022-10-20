#pragma once
#include <Graphics/Resource/GraphicsResource.h>
#include <Graphics/Texture/TextureSamplerCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// Represents a texture sampling object authored by graphics device
	/// </summary>
	class EXPORT TextureSampler : public GraphicsResource
	{
	public:

		FORCEINLINE virtual GraphicsResourceType GetResourceType() const noexcept { return GraphicsResourceType::TextureSampler; }
	protected:
		TextureSampler(const TextureSamplerCreateDesc& desc) : _minFilter(desc.MinFilter),_magFilter(desc.MagFilter),_wrappingS(desc.WrappingS),_wrappingT(desc.WrappingT) {}
		virtual ~TextureSampler() {}

		FORCEINLINE TextureSamplerMinFilter GetMinFilter() const noexcept { return _minFilter; }
		FORCEINLINE TextureSamplerMagFilter GetMaxFilter() const noexcept { return _magFilter; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingS() const noexcept { return _wrappingS; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingT() const noexcept { return _wrappingT; }

	private:
		TextureSamplerMinFilter _minFilter;
		TextureSamplerMagFilter _magFilter;
		TextureSamplerWrapMode _wrappingS;
		TextureSamplerWrapMode _wrappingT;
	};
}