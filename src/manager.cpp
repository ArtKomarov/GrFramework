#include "manager.h"

Manager::Manager()
{

}

void Manager::handleEvent(sf::Event event) {
    for(auto window : windows_) {
        if(window->testEvent(event))
            window->handleEvent(event);
    }
}

void Manager::regWindow(SimpleWindow *window) {
    windows_.push_back(window);
}
