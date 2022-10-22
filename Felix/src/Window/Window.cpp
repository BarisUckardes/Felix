#include "Window.h"
#include <Window/WindowEvents.h>
#include <Graphics/Framebuffer/SwapchainFramebuffer.h>
#include <Graphics/Device/GraphicsDevice.h>

#ifdef FELIX_OS_WINDOWS
#include <Platform/Windows/Window/WindowsWindow.h>
typedef Felix::WindowsWindow WindowsAbstraction;
#endif

namespace Felix
{
	Window* Window::Create(const WindowCreateDesc& desc)
	{
		WindowsAbstraction* window = new WindowsAbstraction(desc);

		return window;
	}
	void Window::Show()
	{
		ShowCore();
		_visible = true;
	}
	void Window::Hide()
	{
		HideCore();
		_visible = false;
	}
	void Window::PollInputEvents()
	{
		/*
		* First clear the former event buffer
		*/
		for (unsigned short i = 0; i <_eventBuffer.size(); i++)
		{
			delete _eventBuffer[i];
		}
		_eventBuffer.clear();

		/*
		* Poll new events
		*/
		PollInputEventsCore();
	}

	void Window::DispatchWindowMessage(WindowEvent* pEvent) noexcept
	{
		WindowEventType type = pEvent->GetEventType();

		switch (type)
		{
			case Felix::WindowEventType::WindowClosed:
			{
				_active = false;
				_visible = false;
				break;
			}
			case Felix::WindowEventType::WindowMoved:
			{
				const WindowMovedEvent* pEventData = (const WindowMovedEvent*)pEvent;

				pEventData->GetPosition(_positionX, _positionY);

;				break;
			}
			case Felix::WindowEventType::WindowResized:
			{
				const WindowResizedEvent* pEventData = (const WindowResizedEvent*)pEvent;
				pEventData->GetSize(_width, _height);

				/*
				* Validate and report swapchain
				*/
				if (_childDevice != nullptr)
				{
					SwapchainFramebuffer* pFramebuffer = (SwapchainFramebuffer*)_childDevice->GetSwapchainFramebuffer();

				}
				break;
			}
			case Felix::WindowEventType::KeyboardDown:
				break;
			case Felix::WindowEventType::KeyboardUp:
				break;
			case Felix::WindowEventType::MouseButtonDown:
				break;
			case Felix::WindowEventType::MouseButtonUp:
				break;
			case Felix::WindowEventType::MouseMoved:
				break;
			case Felix::WindowEventType::MouseScrolled:
				break;
			default:
				break;

		}
		_eventBuffer.push_back(nullptr);
	}
		
	void Window::_BindChildDevice(GraphicsDevice* pChildDevice)
	{
		_childDevice = pChildDevice;
	}

}