//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_MOUSEBUTTONUPEVENT_H
#define STBI_MOUSEBUTTONUPEVENT_H
#include <Window/Events/Mouse/MouseButtonEvent.h>

namespace Felix
{
    class EXPORT MouseButtonUpEvent : public MouseButtonEvent {
    public:
    MouseButtonUpEvent(const unsigned int button) : MouseButtonEvent(button) {}
    ~MouseButtonUpEvent() = default;

    FORCEINLINE WindowEventType GetEventType() const noexcept override final { return WindowEventType::MouseButtonUp;}
    FORCEINLINE std::string GetEventMessage() const noexcept override final { return "MOuse button up";}

    };

}

#endif //STBI_MOUSEBUTTONUPEVENT_H
