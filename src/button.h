#ifndef BUTTON_H
#define BUTTON_H

#include "simplewindow.h"

class Button : public SimpleWindow {
public:
    Button();

    void onClick(const sf::Vector2f& cords) override;
};

#endif // BUTTON_H
