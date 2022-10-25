//
// Created by roveldo on 25.10.2022.
//

#ifdef FELIX_OS_LINUX
#ifndef STBI_LINUXWINDOW_H
#define STBI_LINUXWINDOW_H

#include <Window/Window.h>
#include <X11/Xlib.h>

namespace Felix
{

    class EXPORT LinuxWindow : public Window{
    public:
        LinuxWindow(const WindowCreateDesc& desc);
        virtual ~LinuxWindow() override;

        FORCEINLINE Display* GetXDisplay() const noexcept { return _display;}
        FORCEINLINE XID GetXWindow() const noexcept { return _window;}
        FORCEINLINE int GetXScreen() const noexcept { return _screen;}
    protected:
        void SetTitleCore(const std::string &title) override;
        void SetSizeCore(const unsigned short width, const unsigned short height) override;
        void SetPositionCore(const unsigned short x, const unsigned short y) override;
        void PollInputEventsCore() override;
        void ShowCore() override;
        void HideCore() override;
    private:
        Display* _display;
        XID  _window;
        int _screen;
    };

}



#endif //STBI_LINUXWINDOW_H
#endif
