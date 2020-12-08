#ifndef BUTTON_H
#define BUTTON_H

#include "elemwidget.hpp"

class Button : public ElemWidget {
    ElemWidget* target_;

    void (*onClickFunc_)   (ElemWidget* target);
    void (*onReleaseFunc_) (ElemWidget* target);

public:
    Button(ElemWidget* target,
           void (* const onClickFunc)(ElemWidget* target) = nullptr,
           void (* const onReleaseFunc)(ElemWidget* target) = nullptr);

    Button(const GLfloat* vertices,
           const char*    texPath,
           ElemWidget*    target,
           void (* const onClickFunc)(ElemWidget* target)   = nullptr,
           void (* const onReleaseFunc)(ElemWidget* target) = nullptr);

    /// Set onClick function
    void setOnClickFunc(void (* const onClickFunc)(ElemWidget* target));

    /// Set OnRelease function
    void setOnReleaseFunc(void (* const onReleaseFunc)(ElemWidget* target));

    void onClick() override;

    void onRelease() override;
};

#endif // BUTTON_H
