//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_KEYBOARDKEYUPEVENT_H
#define STBI_KEYBOARDKEYUPEVENT_H

#include <Window/Events/Keyboard/KeyboardKeyEvent.h>

namespace Felix
{
    class EXPORT KeyboardKeyUpEvent : public KeyboardKeyEvent {
    public:
        KeyboardKeyUpEvent(const unsigned int key) : KeyboardKeyEvent(key) {}
        ~KeyboardKeyUpEvent() = default;

        FORCEINLINE WindowEventType GetEventType() const noexcept override final { return WindowEventType::KeyboardUp;}
        FORCEINLINE std::string GetEventMessage() const noexcept override final { return "Keyboard key up event";}
    };
}


#endif //STBI_KEYBOARDKEYUPEVENT_H
