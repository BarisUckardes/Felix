#pragma once
#include <Window/WindowEventType.h>
#include <Core/Core.h>
#include <string>

namespace Felix
{
	/// <summary>
	/// Represents a single event emitted from a window
	/// </summary>
	class WindowEvent
	{
	public:
		WindowEvent() = default;
		~WindowEvent() = default;

		FORCEINLINE bool IsHandled() const noexcept { return _handled; }

		FORCEINLINE virtual WindowEventType GetEventType() const noexcept = 0;
		FORCEINLINE virtual std::string GetEventMessage() const noexcept = 0;

		void MarkHandled() noexcept { _handled = true; }
	protected:

	private:
		bool _handled;
	};
}