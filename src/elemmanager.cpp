#include <iostream>

#include "elemmanager.hpp"

namespace GrFramework {

ElemManager::ElemManager() {

}

void ElemManager::handleEvents() {
    Event* event;

    while(!EventQueue.empty()) {

        event = EventQueue.front();

        EventQueue.pop();

        std::cout << __PRETTY_FUNCTION__ << std::endl;

        for(auto &widget : widgets_) {
            if(widget->testEvent(*event))
                widget->processEvent(*event);
        }
    }
}

void ElemManager::regWidget(ElemWidget *widget) {
    widgets_.push_back(widget);
}

void ElemManager::drawWidgets() const {
    for(auto &widget : widgets_) {
        widget->draw();
    }
}

}
