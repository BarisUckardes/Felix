#ifdef FELIX_OS_WINDOWS
#include "WindowsWindow.h"
#include <Window/WindowEvents.h>

namespace Felix
{
	WindowsWindow* GetUserWindowData(HWND windowHandle)
	{
		return (WindowsWindow*)GetWindowLongPtr(windowHandle, -21);
	}
	LRESULT WindowsWindow::Win32WindowMessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			case WM_CREATE:
			{
				WindowsWindow* pUserWindow = (WindowsWindow*)((LPCREATESTRUCT)lParam)->lpCreateParams;
				SetWindowLongPtr(hwnd, -21, (LONG_PTR)pUserWindow);
				break;
			}
			case WM_CLOSE:
			{
				WindowsWindow* win32Window = GetUserWindowData(hwnd);

				win32Window->DispatchWindowMessage(new WindowClosedEvent());

				break;
			}
			case WM_MOVE:
			{
				WindowsWindow* win32Window = GetUserWindowData(hwnd);

				win32Window->DispatchWindowMessage(new WindowMovedEvent(LOWORD(lParam), HIWORD(lParam)));
				break;
			}
			case WM_SIZE:
			{
				WindowsWindow* win32Window = GetUserWindowData(hwnd);

				win32Window->DispatchWindowMessage(new WindowResizedEvent(LOWORD(lParam), HIWORD(lParam)));
				break;
			}
			case WM_KEYDOWN:
			{
				break;
			}
			case WM_KEYUP:
			{
				break;
			}
			case WM_CHAR:
			{
				break;
			}
			case WM_RBUTTONDOWN:
			{
				break;
			}
			case WM_RBUTTONUP:
			{
				break;
			}
			case WM_LBUTTONDOWN:
			{
				break;
			}
			case WM_LBUTTONUP:
			{
				break;
			}
			case WM_MOUSEMOVE:
			{
				break;
			}
			case WM_MOUSEWHEEL:
			{
				break;
			}
		}

		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	WindowsWindow::WindowsWindow(const WindowCreateDesc& desc) : Window(desc)
	{
		constexpr char WINDOW_CLASS_NAME[] = "Win32Window";

		HINSTANCE processHandle = GetModuleHandle(0);

		/*
		* Create win32 class
		*/
		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wc.lpfnWndProc = (WNDPROC)Win32WindowMessageProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(WindowsWindow);
		wc.hInstance = processHandle;
		wc.hCursor = 0;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = WINDOW_CLASS_NAME;
		wc.hIconSm = NULL;

		ASSERT(RegisterClassEx(&wc) != NULL,"WindowsWindow","Window class registration failed!");

		/*
		* Create window handle
		*/
		HWND windowHandle = CreateWindowEx(
			0,
			WINDOW_CLASS_NAME,
			desc.Title.c_str(),
			WS_OVERLAPPEDWINDOW,
			desc.PositionX,desc.PositionY,desc.Width,desc.Height,
			NULL,
			NULL,
			processHandle,
			this
		);
		ASSERT(windowHandle != NULL,"WindowsWindow","Window creation failed!");

		WindowHandle = windowHandle;
		WindowDeviceContext = GetDC(windowHandle);
	}
	WindowsWindow::~WindowsWindow()
	{
		ReleaseDC(WindowHandle, WindowDeviceContext);
		DestroyWindow(WindowHandle);
	}
	void WindowsWindow::SetTitleCore(const std::string& title)
	{
		SetWindowText(WindowHandle, title.c_str());
	}
	void WindowsWindow::SetSizeCore(const unsigned short width, const unsigned short height)
	{
		SetWindowPos(WindowHandle, NULL, GetPositionX(), GetPositionY(), width,height, 0);
	}
	void WindowsWindow::SetPositionCore(const unsigned short x, const unsigned short y)
	{
		SetWindowPos(WindowHandle, NULL, x, y, GetWidth(), GetHeight(), 0);
	}
	void WindowsWindow::PollInputEventsCore()
	{
		MSG msg = { 0 };
		while (PeekMessage(&msg, WindowHandle, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	void WindowsWindow::ShowCore()
	{
		ShowWindow(WindowHandle, SW_SHOW);
	}
	void WindowsWindow::HideCore()
	{
		ShowWindow(WindowHandle, SW_HIDE);
	}
}
#endif