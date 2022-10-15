#pragma once
#include <Window/WindowEvent.h>

namespace Felix
{
	class EXPORT WindowMovedEvent : public WindowEvent
	{
	public:
		WindowMovedEvent(unsigned short x,unsigned short y) : _positionX(x),_positionY(y) {}
		~WindowMovedEvent() = default;

		FORCEINLINE unsigned short GetPositionX() const noexcept { return _positionX; }
		FORCEINLINE unsigned short GetPositionY() const noexcept { return _positionY; }
		FORCEINLINE void GetPosition(unsigned short& x, unsigned short& y) const noexcept { x = _positionX; y = _positionY; }

		FORCEINLINE WindowEventType GetEventType() const noexcept override { return WindowEventType::WindowMoved; }
		FORCEINLINE std::string GetEventMessage() const noexcept override { return "Window moved"; }
	private:
		unsigned short _positionX;
		unsigned short _positionY;
	};
}