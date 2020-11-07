#ifndef BUTTON_H
#define BUTTON_H

#include "elemwindow.hpp"

class Button : public ElemWindow {
public:
    Button(int width, int height);

    void onClick() override;
};

#endif // BUTTON_H
