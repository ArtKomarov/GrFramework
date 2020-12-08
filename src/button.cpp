#include "button.hpp"

Button::Button(ElemWidget *target,
               void (* const onClickFunc)(ElemWidget* target),
               void (* const onReleaseFunc)(ElemWidget* target) ) :

    ElemWidget     (),
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

void Button::onClick() {
    this->texSetTransformColor(glm::vec3(0.5f, 0.5f, 0.5f));
    if(onClickFunc_ != nullptr)
        (*onClickFunc_)(target_);
}

void Button::onRelease() {
    this->texSetTransformColor(glm::vec3(2.f, 2.f, 2.f));
    if(onReleaseFunc_ != nullptr)
        (*onReleaseFunc_)(target_);
}
