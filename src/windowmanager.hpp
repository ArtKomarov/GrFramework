#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "elemwidget.hpp"
#include "elemmanager.hpp"

class WindowManager : public ElemWidget {
public:
    ElemManager* manager_;

    WindowManager();
    WindowManager(const GLfloat *vertices, const char *texPath);
};

#endif // WINDOWMANAGER_H
