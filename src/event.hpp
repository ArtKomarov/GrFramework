#ifndef EVENT_HPP
#define EVENT_HPP

#include <glm/vec2.hpp>

enum class EventType {
    UNKNOWN,
    EMPTY,
    LEFT_MOUSE_CLICKED,
    LEFT_MOUSE_RELEASED,
    RIGHT_MOUSE_CLICKED,
    RIGHT_MOUSE_RELEASED,
    MOUSE_SCROLL
};

enum class Keyboard {
    NONE,
    Q,
    W,
    E,
    R,
    T
    //...
};

class Event {
    EventType type_;

    glm::vec2* mousePos_;

    Keyboard key_;

public:
    Event(const Event& event);

    Event(Event&& event);

    Event(EventType type, const glm::vec2& mousePos);

    Event(EventType type, Keyboard key);
};

#endif // EVENT_HPP
