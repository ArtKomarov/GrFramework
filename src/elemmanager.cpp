#include "elemmanager.hpp"

ElemManager::ElemManager()
{

}

void ElemManager::handleEvent() {
    for(auto window : windows_) {
        if(window->testEvent())
            window->handleEvent();
    }
}

void ElemManager::regWindow(ElemWindow *window) {
    windows_.push_back(window);
}
