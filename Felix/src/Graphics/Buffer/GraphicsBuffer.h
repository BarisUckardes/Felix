#pragma once
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Buffer/GraphicsBufferCreateDesc.h>
namespace Felix
{
	/// <summary>
	/// Represents a graphics data buffer which is authored by the device
	/// </summary>
	class EXPORT GraphicsBuffer : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE GraphicsBufferUsage GetUsage() const noexcept { return _usage; }
		FORCEINLINE unsigned long GetBufferSize() const noexcept { return _size; }
		FORCEINLINE unsigned int GetSubItemSize() const noexcept { return _subItemSize; }
		FORCEINLINE unsigned int GetSubItemCount() const noexcept { return _subItemCount; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetDeviceObjectType() const noexcept override { return GraphicsDeviceObjectType::Buffer; }

		FORCEINLINE virtual GraphicsBufferType GetBufferType() const noexcept = 0;
	protected:
		GraphicsBuffer(const GraphicsBufferCreateDesc& desc) : _size(desc.Size),_subItemSize(desc.SubItemSize),_subItemCount(desc.SubItemCount),_usage(desc.Usage) {}
		virtual ~GraphicsBuffer() {};
	private:
		const GraphicsBufferUsage _usage;
		const unsigned long _size;
		const unsigned int _subItemSize;
		const unsigned int _subItemCount;
	};
}