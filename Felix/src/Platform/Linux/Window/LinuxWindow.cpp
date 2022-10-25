//
// Created by roveldo on 25.10.2022.
//

#include "LinuxWindow.h"

namespace Felix
{
    Felix::LinuxWindow::LinuxWindow(const Felix::WindowCreateDesc &desc) : Window(desc)
    {
        _display = XOpenDisplay(NULL);

        ASSERT(_display != NULL,"LinuxWindow","Xlib display create failed!");

        _screen = DefaultScreen(_display);

        _window = XCreateSimpleWindow(_display, RootWindow(_display,_screen),
                                      100,100,1024,1024,
                                      1, BlackPixel(_display,_screen), WhitePixel(_display,_screen));

        XSelectInput(_display,_window,ExposureMask | KeyPressMask);

        XMapWindow(_display,_window);

        XStoreName(_display,_window,desc.Title.c_str());
    }

    Felix::LinuxWindow::~LinuxWindow()
    {

    }

    void Felix::LinuxWindow::SetTitleCore(const std::string &title) {
        XStoreName(_display,_window,title.c_str());
    }

    void Felix::LinuxWindow::SetSizeCore(const unsigned short width, const unsigned short height) {
        XResizeWindow(_display,_window,width,height);
    }

    void Felix::LinuxWindow::SetPositionCore(const unsigned short x, const unsigned short y) {
        XMoveWindow(_display,_window,x,y);
    }

    void Felix::LinuxWindow::PollInputEventsCore() {
        while(XPending(_display))
        {
            XEvent  event;
            XNextEvent(_display,&event);
        }
    }

    void Felix::LinuxWindow::ShowCore() {

    }

    void Felix::LinuxWindow::HideCore() {

    }

}