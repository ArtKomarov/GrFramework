#include "elemmanager.hpp"

ElemManager::ElemManager() {

}

void ElemManager::handleEvent() {
    for(auto window : windows_) {
        if(window->testEvent())
            window->handleEvent();
    }
}

void ElemManager::regWindow(ElemWidget *window) {
    windows_.push_back(window);
}
