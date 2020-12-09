#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

//#include <SFML/Graphics.hpp>

#include "elemwidget.hpp"
#include "event.hpp"


namespace GrFramework {

class ElemManager {
    std::vector<ElemWidget*> widgets_;

public:
    ElemManager();

    virtual void handleEvents();

    void regWidget(ElemWidget *widget);

    void drawWidgets() const;

};

}

#endif // MANAGER_H
