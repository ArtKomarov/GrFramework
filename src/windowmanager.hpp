#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "elemwindow.hpp"
#include "elemmanager.hpp"

class WindowManager : public ElemWindow {
public:
    ElemManager* manager_;
    WindowManager(int width, int height);
};

#endif // WINDOWMANAGER_H
