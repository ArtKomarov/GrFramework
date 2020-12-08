#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

//#include <SFML/Graphics.hpp>

#include "elemwidget.hpp"

class ElemManager {
    std::vector<ElemWidget*> windows_;
public:
    ElemManager();

    void handleEvent();

    void regWindow(ElemWidget *window);

};

#endif // MANAGER_H
