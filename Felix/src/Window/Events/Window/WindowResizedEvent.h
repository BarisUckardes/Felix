#pragma once
#include <Window/WindowEvent.h>

namespace Felix
{
	/// <summary>
	/// Represent the window resizing event emittted form a window
	/// </summary>
	class EXPORT WindowResizedEvent final : public WindowEvent
	{
	public:
		WindowResizedEvent(const unsigned short width, const unsigned short height) : _width(width),_height(height) {}
		~WindowResizedEvent() = default;

		FORCEINLINE unsigned short GetWidth() const noexcept { return _width; }
		FORCEINLINE unsigned short GetHeight() const noexcept { return _height; }
		FORCEINLINE void GetSize(unsigned short& width, unsigned short& height) const noexcept { width = _width; height = _height; }

		FORCEINLINE WindowEventType GetEventType() const noexcept override { return WindowEventType::WindowResized; }
		FORCEINLINE std::string GetEventMessage() const noexcept override { return "Window resized"; }
		
	private:
		const unsigned short _width;
		const unsigned short _height;
	};
}