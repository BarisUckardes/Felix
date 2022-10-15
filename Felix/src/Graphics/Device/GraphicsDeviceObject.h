#pragma once
#include <Core/Core.h>
#include <Graphics/Device/GraphicsDeviceObjectType.h>
#include <string>

namespace Felix
{
	class GraphicsDevice;

	/// <summary>
	/// Represents a graphics object which is authored by a graphics device
	/// </summary>
	class EXPORT GraphicsDeviceObject
	{
		friend class GraphicsDevice;
	public:
		GraphicsDeviceObject() : _ownerDevice(nullptr) {}
		virtual ~GraphicsDeviceObject() {};

		FORCEINLINE std::string GetName() const noexcept { return _name; }
		FORCEINLINE GraphicsDevice* GetOwnerDevice() const noexcept { return _ownerDevice; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetDeviceObjectType() const noexcept = 0;

		FORCEINLINE void SetName(const std::string& name) noexcept { _name = name; }
	private:
		void _SetOwnerDevice(GraphicsDevice* pDevice) { _ownerDevice = pDevice; }
	private:
		GraphicsDevice* _ownerDevice;
		std::string _name;
	};
}