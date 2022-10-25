//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_MOUSEMOVEDEVENT_H
#define STBI_MOUSEMOVEDEVENT_H
#include <Window/WindowEvent.h>

namespace Felix
{
    class EXPORT MouseMovedEvent final : public WindowEvent {
    public:

        MouseMovedEvent(const unsigned int x,const unsigned int y) : _x(x),_y(y) {}
        ~MouseMovedEvent() = default;

        FORCEINLINE unsigned int GetPositionX() const noexcept { return _x;}
        FORCEINLINE unsigned int GetPositionY() const noexcept { return _y;}
        FORCEINLINE void GetPosition(unsigned int& x,unsigned int& y) { x = _x; y= _y;}

        FORCEINLINE WindowEventType GetEventType() const noexcept override { return WindowEventType::MouseMoved;}
        FORCEINLINE std::string GetEventMessage() const noexcept override { return "Window moved";}
    private:
        unsigned int _x;
        unsigned int _y;
    };
}


#endif //STBI_MOUSEMOVEDEVENT_H
