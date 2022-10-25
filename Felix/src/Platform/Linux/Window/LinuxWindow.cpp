//
// Created by roveldo on 25.10.2022.
//

#include "LinuxWindow.h"
#include <Window/WindowEvents.h>
namespace Felix
{
    Felix::LinuxWindow::LinuxWindow(const Felix::WindowCreateDesc &desc) : Window(desc)
    {
        /* Initialize the library */
        if (!glfwInit())
            return;

#ifdef FELIX_DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

        /* Create a windowed mode window and its OpenGL context */
        _window = glfwCreateWindow(desc.Width, desc.Height, desc.Title.c_str(), NULL, NULL);

        glfwSetWindowPos(_window,desc.PositionX,desc.PositionY);

        ASSERT(_window != nullptr,"LinuxWindow","Couldnt create window")

        /* Make the window's context current */
        glfwMakeContextCurrent(_window);

        /*
         * Setup events
         */
        glfwSetWindowUserPointer(_window,this);
        glfwSetWindowCloseCallback(_window,LinuxWindow::OnWindowClosed);
        glfwSetKeyCallback(_window,LinuxWindow::OnKey);
        glfwSetMouseButtonCallback(_window,LinuxWindow::OnMouseButton);
        glfwSetCursorPosCallback(_window,LinuxWindow::OnMouseMoved);
        glfwSetScrollCallback(_window,LinuxWindow::OnMouseWheel);

    }

    Felix::LinuxWindow::~LinuxWindow()
    {
        glfwDestroyWindow(_window);
    }

    void Felix::LinuxWindow::SetTitleCore(const std::string &title) {
        glfwSetWindowTitle(_window,title.c_str());
    }

    void Felix::LinuxWindow::SetSizeCore(const unsigned short width, const unsigned short height) {
        glfwSetWindowSize(_window,width,height);
    }

    void Felix::LinuxWindow::SetPositionCore(const unsigned short x, const unsigned short y) {
        glfwSetWindowPos(_window,x,y);
    }

    void Felix::LinuxWindow::PollInputEventsCore() {
        glfwPollEvents();

    }

    void Felix::LinuxWindow::ShowCore() {

    }

    void Felix::LinuxWindow::HideCore() {

    }

    void LinuxWindow::OnWindowClosed(GLFWwindow *pWindow)
    {
        LinuxWindow* pFelixWindow = (LinuxWindow*)glfwGetWindowUserPointer(pWindow);

        pFelixWindow->DispatchWindowMessage(new WindowClosedEvent());
    }

    void LinuxWindow::OnKey(GLFWwindow *pWindow, int key, int scanCode, int action, int mods)
    {
        LinuxWindow* pFelixWindow = (LinuxWindow*)glfwGetWindowUserPointer(pWindow);

        switch (action)
        {
            case GLFW_PRESS:
            {
                pFelixWindow->DispatchWindowMessage(new KeyboardKeyDownEvent(key));
                break;
            }
            case GLFW_RELEASE:
            {
                pFelixWindow->DispatchWindowMessage(new KeyboardKeyUpEvent(key));
                break;
            }
        }

    }

    void LinuxWindow::OnMouseButton(GLFWwindow *pWindow, int button, int action, int mods)
    {
        LinuxWindow* pFelixWindow = (LinuxWindow*)glfwGetWindowUserPointer(pWindow);

        switch (action) {
            case GLFW_PRESS:
            {
                pFelixWindow->DispatchWindowMessage(new MouseButtonDownEvent(button));
                break;
            }
            case GLFW_RELEASE:
            {
                pFelixWindow->DispatchWindowMessage(new MouseButtonUpEvent(button));
                break;
            }
        }

    }

    void LinuxWindow::OnMouseMoved(GLFWwindow *pWindow, double x, double y)
    {
        LinuxWindow* pFelixWindow = (LinuxWindow*)glfwGetWindowUserPointer(pWindow);

        pFelixWindow->DispatchWindowMessage(new MouseMovedEvent(x,y));
    }

    void LinuxWindow::OnMouseWheel(GLFWwindow *pWindow, double x, double y)
    {
        LinuxWindow* pFelixWindow = (LinuxWindow*)glfwGetWindowUserPointer(pWindow);

        pFelixWindow->DispatchWindowMessage(new MouseWheelScrolled(x,y));
    }

}