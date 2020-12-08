#include "event.hpp"

Event::Event(const Event &event) :
    type_(event.type_),
    key_(event.key_) {

    if(event.mousePos_ != nullptr)
        mousePos_ = new glm::vec2(*event.mousePos_);
}

Event::Event(Event &&event) :
    type_     (event.type_),
    mousePos_ (event.mousePos_),
    key_      (event.key_) {

    event.type_     = EventType::EMPTY;
    event.mousePos_ = nullptr;
    event.key_      = Keyboard::NONE;

}

Event::Event(EventType type, const glm::vec2 &mousePos) :
    type_(type),
    mousePos_(new glm::vec2(mousePos)),
    key_(Keyboard::NONE) {}

Event::Event(EventType type, Keyboard key) :
    type_(type),
    mousePos_(nullptr),
    key_(key) {}
