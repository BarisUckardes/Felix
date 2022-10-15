#pragma once
namespace Felix
{
	/// <summary>
	/// Supported window events
	/// </summary>
	enum class WindowEventType
	{
		WindowClosed,
		WindowMoved,
		WindowResized,

		KeyboardDown,
		KeyboardUp,

		MouseButtonDown,
		MouseButtonUp,
		MouseMoved,
		MouseScrolled
	};
}