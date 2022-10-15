#pragma once
#include <Window/WindowCreateDesc.h>
#include <Core/Core.h>
#include <vector>
#include <Window/WindowEvent.h>

namespace Felix
{
	/// <summary>
	/// Represents a platform-agnostic window
	/// </summary>
	class EXPORT Window
	{
	public:
		static Window* Create(const WindowCreateDesc& desc);
	public:
		FORCEINLINE std::string GetTitle() const noexcept { return _title; }
		FORCEINLINE unsigned short GetWidth() const noexcept { return _width; }
		FORCEINLINE unsigned short GetHeight() const noexcept { return _height; }
		FORCEINLINE unsigned short GetPositionX() const noexcept { return _positionX; }
		FORCEINLINE unsigned short GetPositionY() const noexcept { return _positionY; }
		FORCEINLINE void GetPosition(unsigned short& x, unsigned short& y) noexcept { x = _positionX; y = _positionY; }
		FORCEINLINE bool IsActive() const noexcept { return _active; }
		FORCEINLINE bool IsVisible() const noexcept { return _visible; }
		std::vector<WindowEvent*> GetEventBuffer() const noexcept { return _eventBuffer; }

		FORCEINLINE void SetTitle(const std::string& title) { SetTitleCore(title); _title = title; }
		FORCEINLINE void SetSize(const unsigned short width, const unsigned short height) { SetSizeCore(width, height); _width = width; _height = height; }
		FORCEINLINE void SetPosition(const unsigned short x, const unsigned short y) { SetPositionCore(x, y); _positionX = x; _positionY = y; }

		void Show();
		void Hide();
		void PollInputEvents();
	protected:
		Window(const WindowCreateDesc& desc) : _title(desc.Title), _width(desc.Width), _height(desc.Height), _positionX(desc.PositionX), _positionY(desc.PositionY),_active(true) {}
		virtual ~Window() {}

		FORCEINLINE void DispatchWindowMessage(WindowEvent* pEvent) noexcept;

		FORCEINLINE virtual void SetTitleCore(const std::string& title) = 0;
		FORCEINLINE virtual void SetSizeCore(const unsigned short width, const unsigned short height) = 0;
		FORCEINLINE virtual void SetPositionCore(const unsigned short x, const unsigned short y) = 0;

		virtual void PollInputEventsCore() = 0;
		virtual void ShowCore() = 0;
		virtual void HideCore() = 0;

	private:
		std::vector<WindowEvent*> _eventBuffer;
		std::string _title;
		unsigned short _width;
		unsigned short _height;
		unsigned short _positionX;
		unsigned short _positionY;
		bool _active;
		bool _visible;
	};
}