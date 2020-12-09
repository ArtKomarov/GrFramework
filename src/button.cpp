#include <iostream>

#include "button.hpp"
#include "event.hpp"

namespace GrFramework {

Button::Button(ElemWidget *target,
               double posX,  double posY,
               double width, double height,
               void (* const onClickFunc)(ElemWidget* target),
               void (* const onReleaseFunc)(ElemWidget* target) ) :

    ElemWidget     (posX, posY, width, height),
    target_        (target),
    onClickFunc_   (onClickFunc),
    onReleaseFunc_ (onReleaseFunc) {}

Button::Button(const GLfloat* vertices,
               const char*    texPath,
               ElemWidget*    target,
               void (* const onClickFunc)(ElemWidget* target),
               void (* const onReleaseFunc)(ElemWidget* target) ) :

    ElemWidget     (vertices, texPath),
    target_        (target),
    onClickFunc_   (onClickFunc),
    onReleaseFunc_ (onReleaseFunc) {}

void Button::setOnClickFunc(void (* const onClickFunc)(ElemWidget *)) {
    onClickFunc_ = onClickFunc;
}

void Button::setOnReleaseFunc(void (* const onReleaseFunc)(ElemWidget *)) {
    onReleaseFunc_ = onReleaseFunc;
}

bool Button::testEvent(const Event &event) const {
    $;
    switch (event.type_) {
    case EventType::LEFT_MOUSE_CLICKED:
        std::cout << __PRETTY_FUNCTION__ << ": cursorPos = "
                  << cursorPosition[0] << " " << cursorPosition[1]
                  << ". Button pos: " << this->getPosX() << " " << this->getPosY()
                  << ". Size: " << this->getWidth() << " " << this->getHeigth() << std::endl;

        if(    (cursorPosition[0] >= this->getPosX())
            && (cursorPosition[0] <= this->getPosX() + this->getWidth())
            && (cursorPosition[1] >= this->getPosY())
            && (cursorPosition[1] <= this->getPosY() + this->getHeigth())
          ) {
            return true;
        }

        break;

    case EventType::LEFT_MOUSE_RELEASED:
        return true;

    default:
        break;
    }

    return false;
}

void Button::processEvent(const Event &event) {
    $;
    switch (event.type_) {
    case EventType::LEFT_MOUSE_CLICKED:
        this->onClick();
        break;
    case EventType::LEFT_MOUSE_RELEASED:
        this->onRelease();
        break;
    default:
        break;
    }
}

void Button::onClick() {
    $;
    this->texSetTransformColor(glm::vec3(0.5f, 0.5f, 0.5f));
    if(onClickFunc_ != nullptr)
        (*onClickFunc_)(target_);
}

void Button::onRelease() {
    this->texSetTransformColor(glm::vec3(1.f, 1.f, 1.f));
    if(onReleaseFunc_ != nullptr)
        (*onReleaseFunc_)(target_);
}

}
