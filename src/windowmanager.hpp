#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "elemwidget.hpp"
#include "elemmanager.hpp"

namespace GrFramework {

class WindowManager : public ElemWidget {
public:
    ElemManager* manager_;

    WindowManager(double posX, double posY, double width, double height);
    WindowManager(const GLfloat *vertices, const char *texPath);

    ~WindowManager();

    void draw() const override;
};

}

#endif // WINDOWMANAGER_H
