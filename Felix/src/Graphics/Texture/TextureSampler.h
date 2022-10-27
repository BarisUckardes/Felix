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
			_filter(desc.Filter),
			_wrappingU(desc.WrappingU), _wrappingV(desc.WrappingV),_wrappingW(desc.WrappingW),
			_maxAnisotropy(desc.MaxAnisotropy) {}
		virtual ~TextureSampler() {}

		FORCEINLINE TextureSamplerFilter GetFilter() const noexcept { return _filter; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingU() const noexcept { return _wrappingU; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingV() const noexcept { return _wrappingV; }
		FORCEINLINE TextureSamplerWrapMode GetWrappingW() const noexcept { return _wrappingW; }
		FORCEINLINE unsigned int GetMaxAnisotropy() const noexcept { return _maxAnisotropy; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetDeviceObjectType() const noexcept { return GraphicsDeviceObjectType::TextureSampler; }
	private:
        TextureSamplerFilter _filter;
		TextureSamplerWrapMode _wrappingU;
		TextureSamplerWrapMode _wrappingV;
		TextureSamplerWrapMode _wrappingW;
		unsigned int _maxAnisotropy;
	};
}