#include "windowmanager.hpp"

WindowManager::WindowManager() :
    ElemWidget() {
}

WindowManager::WindowManager(const GLfloat *vertices, const char *texPath) :
    ElemWidget(vertices, texPath) {

}
