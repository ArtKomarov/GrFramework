#include "windowmanager.hpp"

namespace GrFramework {

WindowManager::WindowManager(double posX, double posY, double width, double height) :
    ElemWidget(posX, posY, width, height),
    manager_(new ElemManager()) {
}

WindowManager::WindowManager(const GLfloat *vertices, const char *texPath) :
    ElemWidget(vertices, texPath),
    manager_(new ElemManager()) {

}

void WindowManager::draw() const {
    manager_->drawWidgets();
}

WindowManager::~WindowManager() {
    delete manager_;
}

}
