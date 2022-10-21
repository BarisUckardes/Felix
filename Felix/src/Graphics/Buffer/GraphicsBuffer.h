#pragma once
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Buffer/GraphicsBufferCreateDesc.h>
#include <Graphics/Buffer/GraphicsBufferUpdateDesc.h>
namespace Felix
{
	/// <summary>
	/// Represents a graphics data buffer which is authored by the device
	/// </summary>
	class EXPORT GraphicsBuffer : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE GraphicsBufferType GetBufferType() const noexcept { return _type; }
		FORCEINLINE GraphicsBufferUsage GetUsage() const noexcept { return _usage; }
		FORCEINLINE unsigned long GetBufferSize() const noexcept { return _size; }
		FORCEINLINE unsigned int GetSubItemSize() const noexcept { return _subItemSize; }
		FORCEINLINE unsigned int GetSubItemCount() const noexcept { return _subItemCount; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetDeviceObjectType() const noexcept override { return GraphicsDeviceObjectType::Buffer; }
	protected:
		GraphicsBuffer(const GraphicsBufferCreateDesc& desc) : _size(desc.SubItemSize*desc.SubItemCount),_type(desc.Type), _subItemSize(desc.SubItemSize), _subItemCount(desc.SubItemCount), _usage(desc.Usage) {}
		virtual ~GraphicsBuffer() {};
	private:
		const GraphicsBufferType _type;
		const GraphicsBufferUsage _usage;
		const unsigned long _size;
		const unsigned int _subItemSize;
		const unsigned int _subItemCount;
	};
}