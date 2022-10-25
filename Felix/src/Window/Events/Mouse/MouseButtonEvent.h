//
// Created by roveldo on 25.10.2022.
//

#ifndef STBI_MOUSEBUTTONEVENT_H
#define STBI_MOUSEBUTTONEVENT_H
#include <Window/WindowEvent.h>

namespace Felix
{
    class EXPORT MouseButtonEvent : public WindowEvent{
    public:
        FORCEINLINE unsigned int GetRelatedButton() const noexcept { return _button;}
    protected:
        MouseButtonEvent(const unsigned int button) : _button(button) {}
        ~MouseButtonEvent() = default;

    private:
        const unsigned int _button;
    };

}

#endif //STBI_MOUSEBUTTONEVENT_H
