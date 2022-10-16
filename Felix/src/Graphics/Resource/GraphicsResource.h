#pragma once
#include <Graphics/Resource/GraphicsResourceCreateDesc.h>
#include <Graphics/Device/GraphicsDeviceObject.h>

namespace Felix
{
	class EXPORT GraphicsResource : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE GraphicsResourceType GetResourceType() const noexcept { return _type; }
		FORCEINLINE GraphicsDeviceObject* GetResource() const noexcept { return _deviceObject; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetDeviceObjectType() const noexcept final { return GraphicsDeviceObjectType::Resource; }
	protected:
		GraphicsResource(const GraphicsResourceCreateDesc& desc) : _type(desc.Type),_deviceObject(desc.pDeviceObject) {}
		virtual ~GraphicsResource() {}
	private:
		const GraphicsResourceType _type;
		GraphicsDeviceObject* _deviceObject;
	};
}