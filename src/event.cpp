#include <iostream>

#include "event.hpp"

namespace GrFramework {

Event::Event(const Event &event) :
    type_(event.type_),
    key_(event.key_) {

    if(event.mousePos_ != nullptr) {
        mousePos_ = new double(2);
        mousePos_[0] = event.mousePos_[0];
        mousePos_[1] = event.mousePos_[1];
    }
}

Event::Event(Event &&event) :
    type_     (event.type_),
    mousePos_ (event.mousePos_),
    key_      (event.key_) {

    event.type_     = EventType::EMPTY;
    event.mousePos_ = nullptr;
    event.key_      = Keyboard::NONE;

}

Event::Event(EventType type, const double *mousePos) :
    type_     (type),
    mousePos_ (new double(2)),
    key_      (Keyboard::NONE) {}

Event::Event(EventType type, Keyboard key) :
    type_     (type),
    mousePos_ (nullptr),
    key_      (key) {}

std::queue<Event*> EventQueue;

double cursorPosition[2] = {0, 0};

void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
    std::cout << __PRETTY_FUNCTION__
              << ": xPos = " << xPos
              << ", yPos = " << yPos;
              //<< std::endl;

    int windowWidth;
    int windowHeight;

    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    std::cout << " winWidth = "   << windowWidth
              << ", winHeight = " << windowHeight << std::endl;

    cursorPosition[0] = (xPos - windowWidth  / 2) / (windowWidth / 2);
    cursorPosition[1] = (windowHeight / 2 - yPos) / (windowHeight / 2);
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    $;
    if(button == GLFW_MOUSE_BUTTON_LEFT) {
        EventType type = EventType::EMPTY;

        if(action == GLFW_PRESS) {
            type = EventType::LEFT_MOUSE_CLICKED;
        }
        else if(action == GLFW_RELEASE) {
            type = EventType::LEFT_MOUSE_RELEASED;
        }

        Event* event = new Event(type, cursorPosition);
        EventQueue.push(event);
    }
}

}

