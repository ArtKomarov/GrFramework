#ifndef EVENT_HPP
#define EVENT_HPP

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include <queue>

#include <iostream>

#define $ std::cout << __PRETTY_FUNCTION__ << std::endl

namespace GrFramework {

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

struct Event {
    EventType type_;

    double* mousePos_;

    Keyboard key_;

    Event(const Event& event);

    Event(Event&& event);

    Event(EventType type, const double* mousePos);

    Event(EventType type, Keyboard key);
};

/// Cursor position callback
void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);

/// Click on mouse callback
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

/// Event queue for handling events
extern std::queue<Event*> EventQueue;

/// Current cursor position for click events
extern double cursorPosition[2];

}

#endif // EVENT_HPP
