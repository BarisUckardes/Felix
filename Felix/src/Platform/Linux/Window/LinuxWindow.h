//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_LINUXWINDOW_H
#define STBI_LINUXWINDOW_H

#include <Window/Window.h>

namespace Felix
{

    class EXPORT LinuxWindow : public Window{
    public:
        LinuxWindow(const WindowCreateDesc& desc);
        virtual ~LinuxWindow() override;

    protected:
        void SetTitleCore(const std::string &title) override;

        void SetSizeCore(const unsigned short width, const unsigned short height) override;

        void SetPositionCore(const unsigned short x, const unsigned short y) override;

        void PollInputEventsCore() override;

        void ShowCore() override;

        void HideCore() override;
    };

}



#endif //STBI_LINUXWINDOW_H
