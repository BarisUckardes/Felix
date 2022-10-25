//
// Created by roveldo on 25.10.2022.
//

#ifdef FELIX_OS_LINUX
#ifndef STBI_LINUXWINDOW_H
#define STBI_LINUXWINDOW_H

#include <Window/Window.h>
#include <GLFW/glfw3.h>

namespace Felix
{

    class EXPORT LinuxWindow : public Window{
    public:
        LinuxWindow(const WindowCreateDesc& desc);
        virtual ~LinuxWindow() override;

        FORCEINLINE GLFWwindow* GetGLFWWindow() const { return _window;}
    protected:
        void SetTitleCore(const std::string &title) override;
        void SetSizeCore(const unsigned short width, const unsigned short height) override;
        void SetPositionCore(const unsigned short x, const unsigned short y) override;
        void PollInputEventsCore() override;
        void ShowCore() override;
        void HideCore() override;
    private:
        static void OnWindowClosed(GLFWwindow* pWindow);
        static void OnKey(GLFWwindow* pWindow,int key,int scanCode,int action,int mods);
        static void OnMouseButton(GLFWwindow* pWindow,int button,int action,int mods);
        static void OnMouseMoved(GLFWwindow* pWindow,double  x,double y);
        static void OnMouseWheel(GLFWwindow* pWindow,double x,double y);

    private:
        GLFWwindow* _window;
    };

}



#endif //STBI_LINUXWINDOW_H
#endif
