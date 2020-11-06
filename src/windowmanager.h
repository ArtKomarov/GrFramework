#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "simplewindow.h"
#include "manager.h"

class WindowManager : public SimpleWindow {
    Manager* manager_;
public:
    WindowManager();
};

#endif // WINDOWMANAGER_H
