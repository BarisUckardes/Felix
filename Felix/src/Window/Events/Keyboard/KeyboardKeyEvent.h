//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_KEYBOARDKEYEVENT_H
#define STBI_KEYBOARDKEYEVENT_H

#include <Window/WindowEvent.h>

namespace Felix
{
    class EXPORT KeyboardKeyEvent : public WindowEvent {
    public:
        FORCEINLINE unsigned int GetRelatedKey() const noexcept { return _key;}
    protected:
        KeyboardKeyEvent(const unsigned int key) : _key(key) {}
        ~KeyboardKeyEvent() = default;

    private:
        const unsigned int _key;
    };

}

#endif //STBI_KEYBOARDKEYEVENT_H
