#ifndef MANAGER_H
#define MANAGER_H

#include <SFML/Graphics.hpp>

#include "simplewindow.h"

class Manager {
    std::vector<SimpleWindow*> windows_;
public:
    Manager();

    void handleEvent(sf::Event event);

    void regWindow(SimpleWindow* window);

};

#endif // MANAGER_H
