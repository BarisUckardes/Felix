#pragma once
#include <Window/WindowEvent.h>

namespace Felix
{
	class WindowClosedEvent final : public WindowEvent
	{
	public:
		WindowClosedEvent() = default;
		~WindowClosedEvent() = default;

		FORCEINLINE virtual WindowEventType GetEventType() const noexcept override final { return WindowEventType::WindowClosed; }
		FORCEINLINE virtual std::string GetEventMessage() const noexcept override final { return "Window closed"; }
	};
}