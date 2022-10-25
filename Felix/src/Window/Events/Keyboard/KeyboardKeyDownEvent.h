//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_KEYBOARDKEYDOWNEVENT_H
#define STBI_KEYBOARDKEYDOWNEVENT_H

#include <Window/Events/Keyboard/KeyboardKeyEvent.h>

namespace Felix
{
    class EXPORT KeyboardKeyDownEvent : public KeyboardKeyEvent {

    public:
        KeyboardKeyDownEvent(const unsigned int key) : KeyboardKeyEvent(key) {}
        ~KeyboardKeyDownEvent() = default;

        FORCEINLINE WindowEventType GetEventType() const noexcept override final { return WindowEventType::KeyboardDown;}
        FORCEINLINE std::string GetEventMessage() const noexcept override final { return "Keyboard key down!";}
    };

}

#endif //STBI_KEYBOARDKEYDOWNEVENT_H
