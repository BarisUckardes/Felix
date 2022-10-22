#pragma once
#include <Window/Window.h>

#ifdef FELIX_OS_WINDOWS
#include <Windows.h>

namespace Felix
{
	/// <summary>
	/// Windows implementation of a window
	/// </summary>
	class EXPORT WindowsWindow final : public Window
	{
	private:
		static LRESULT CALLBACK Win32WindowMessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	public:
		WindowsWindow(const WindowCreateDesc& desc);
		virtual ~WindowsWindow() override;

		FORCEINLINE HWND GetWin32WindowHandle() const noexcept { return WindowHandle; }
		FORCEINLINE HDC GetWin32WindowDeviceContext() const noexcept { return WindowDeviceContext; }

	protected:
		virtual void SetTitleCore(const std::string& title) override final;
		virtual void SetSizeCore(const unsigned short width, const unsigned short height) override final;
		virtual void SetPositionCore(const unsigned short x, const unsigned short y) override final;
		virtual void PollInputEventsCore() override final;
		virtual void ShowCore() override final;
		virtual void HideCore() override final;
	private:
		HWND WindowHandle;
		HDC WindowDeviceContext;
	};
}
#endif

