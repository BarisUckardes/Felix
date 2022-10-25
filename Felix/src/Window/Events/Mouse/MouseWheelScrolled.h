//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_MOUSEWHEELSCROLLED_H
#define STBI_MOUSEWHEELSCROLLED_H

#include <Window/WindowEvent.h>

namespace Felix
{

    class EXPORT MouseWheelScrolled : public WindowEvent {
    public:
        MouseWheelScrolled(const unsigned int horizontal,const unsigned int vertical) : _horizontal(horizontal),_vertical(vertical) {}
        ~MouseWheelScrolled() = default;

        FORCEINLINE unsigned int GetHorizontal() const noexcept { return _horizontal;}
        FORCEINLINE unsigned int GetVertical() const noexcept  { return _vertical;}

        FORCEINLINE WindowEventType GetEventType() const noexcept override final { return WindowEventType::MouseScrolled;}
        FORCEINLINE std::string GetEventMessage() const noexcept override final { return "Mouse wheel scrolled!";}

    private:
        const unsigned int _horizontal;
        const unsigned int _vertical;
    };
}


#endif //STBI_MOUSEWHEELSCROLLED_H
