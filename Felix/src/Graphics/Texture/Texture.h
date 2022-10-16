#pragma once
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Texture/TextureCreateDesc.h>

namespace Felix
{
	/// <summary>
	/// A graphics texture which is authored by a graphics device
	/// </summary>
	class EXPORT Texture : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE TextureType GetTextureType() const noexcept { return _type; }
		FORCEINLINE TextureUsage GetUsage() const noexcept { return _usage; }
		FORCEINLINE TextureFormat GetFormat() const noexcept { return _format; }
		FORCEINLINE unsigned int GetWidth() const noexcept { return _width; }
		FORCEINLINE unsigned int GetHeight() const noexcept { return _height; }
		FORCEINLINE unsigned int GetDepth() const noexcept { return _depth; }

		FORCEINLINE GraphicsDeviceObjectType GetDeviceObjectType() const noexcept final override { return GraphicsDeviceObjectType::Texture; }

	protected:
		Texture(const TextureCreateDesc& desc) : _type(desc.Type),_usage(desc.Usage),_format(desc.Format),_width(desc.Width),_height(desc.Height),_depth(desc.Depth) {}
		virtual ~Texture() {}
	private:
		TextureType _type;
		TextureUsage _usage;
		TextureFormat _format;
		unsigned int _width;
		unsigned int _height;
		unsigned int _depth;
	};
}
