#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

//#include <SFML/Graphics.hpp>

#include "elemwindow.hpp"

class ElemManager {
    std::vector<ElemWindow*> windows_;
public:
    ElemManager();

    void handleEvent();

    void regWindow(ElemWindow *window);

};

#endif // MANAGER_H
