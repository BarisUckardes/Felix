//
// Created by roveldo on 25.10.2022.
//

#include <X11/Xutil.h>
#include "LinuxWindow.h"
namespace Felix
{
    Felix::LinuxWindow::LinuxWindow(const Felix::WindowCreateDesc &desc) : Window(desc)
    {
        _display = XOpenDisplay(NULL);

        ASSERT(_display != NULL,"LinuxWindow","Xlib display create failed!");

        _screen = DefaultScreen(_display);

        _visual =  XDefaultVisual(_display,_screen);

        XSetWindowAttributes  windowAttribs;
        windowAttribs.border_pixel = BlackPixel(_display,_screen);
        windowAttribs.background_pixel = WhitePixel(_display,_screen);
        windowAttribs.override_redirect = true;
        windowAttribs.colormap = XCreateColormap(_display,RootWindow(_display,_screen),_visual,AllocNone);
        windowAttribs.event_mask = ExposureMask;

        _window = XCreateWindow(_display, RootWindow(_display,_screen),
                                      desc.PositionX,desc.PositionY,desc.Width,desc.Height,
                                      0,
                                      DefaultDepth(_display,_screen),
                                      InputOutput,
                                      _visual,
                                      CWBackPixel | CWColormap | CWBorderPixel | CWEventMask,&windowAttribs);

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