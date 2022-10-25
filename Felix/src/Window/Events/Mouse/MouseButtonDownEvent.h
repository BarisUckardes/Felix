//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_MOUSEBUTTONDOWNEVENT_H
#define STBI_MOUSEBUTTONDOWNEVENT_H

#include <Window/Events/Mouse/MouseButtonEvent.h>

namespace Felix
{
    class EXPORT MouseButtonDownEvent : public MouseButtonEvent {
    public:
        MouseButtonDownEvent(const unsigned int button) : MouseButtonEvent(button) {}
        ~MouseButtonDownEvent() = default;

        FORCEINLINE WindowEventType GetEventType() const noexcept override final { return WindowEventType::MouseButtonDown;}
        FORCEINLINE std::string GetEventMessage() const noexcept override final { return "Mouse button pressed";}
    };

}

#endif //STBI_MOUSEBUTTONDOWNEVENT_H
