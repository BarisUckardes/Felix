#pragma once
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Texture/TextureSamplerCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// Represents a texture sampling object authored by graphics device
	/// </summary>
	class EXPORT TextureSampler : public GraphicsDeviceObject
	{
	public:
	protected:
		TextureSampler(const TextureSamplerCreateDesc& desc) :
			_minFilter(desc.MinFilter), _magFilter(desc.MagFilter),
			_wrappingS(desc.WrappingS), _wrappingT(desc.WrappingT),_wrappingR(desc.WrappingR),
			_maxAnisotropy(desc.MaxAnisotropy) {}
		virtual ~TextureSampler() {}

		FORCEINLINE TextureSamplerMinFilter GetMinFilter() const noexcept { return _minFilter; }
		FORCEINLINE TextureSamplerMagFilter GetMaxFilter() const noexcept { return _magFilter; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingS() const noexcept { return _wrappingS; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingT() const noexcept { return _wrappingT; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingR() const noexcept { return _wrappingR; }
		FORCEINLINE unsigned int GetMaxAnisotropy() const noexcept { return _maxAnisotropy; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetDeviceObjectType() const noexcept { return GraphicsDeviceObjectType::TextureSampler; }
	private:
		TextureSamplerMinFilter _minFilter;
		TextureSamplerMagFilter _magFilter;
		TextureSamplerWrapMode _wrappingS;
		TextureSamplerWrapMode _wrappingT;
		TextureSamplerWrapMode _wrappingR;
		unsigned int _maxAnisotropy;
	};
}