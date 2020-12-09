#include "elemwidget.hpp"

namespace GrFramework {

// Proteted texture functions
void ElemWidget::texSetTransformColor(const glm::vec3 &vec) {
    texture_->setTransformColor(vec);
}

void ElemWidget::texSetTransformTexCoords(const glm::mat2 &matrix) {
    texture_->setTransformTexCoords(matrix);
}

void ElemWidget::texSetTransformPos(const glm::mat4 &matrix) {
    texture_->setTransformPos(matrix);
}

// Constructors
ElemWidget::ElemWidget(double posX, double posY, double width, double height) :
    texture_  (nullptr),
    isHidden_ (false),
    posX_     (posX),
    posY_     (posY),
    width_    (width),
    height_   (height) {}

ElemWidget::ElemWidget(const GLfloat *vertices, const char *texPath) :
    texture_  (new Texture(vertices, texPath)),
    isHidden_ (false),
    posX_     (static_cast<double>(vertices[8 * 2])),
    posY_     (static_cast<double>(vertices[8 * 2 + 1])),
    width_    (static_cast<double>(vertices[8 * 1] - vertices[8 * 2])),
    height_   (static_cast<double>(vertices[8 * 3 + 1] - vertices[8 * 2 + 1])) {}

// Draw texture if exists
void ElemWidget::draw() const {
    if(texture_) {
        texture_->draw();
    }
}

void ElemWidget::update() {}

bool ElemWidget::isHidden() const {
    return isHidden_;
}

bool ElemWidget::testClick() const {
    return false;
}

bool ElemWidget::testEvent(const Event& event) const {
    return false;
}

void ElemWidget::processEvent(const Event& event) {}

void ElemWidget::onClick() {}

void ElemWidget::onRelease() {}

void ElemWidget::onKey(int key) {}

void ElemWidget::onMove() {}

void ElemWidget::onOpen() {}

void ElemWidget::onClose() {}

void ElemWidget::onFocus() {}

void ElemWidget::onResize() {}

void ElemWidget::changeColor(const void *data) {}

void ElemWidget::changePos(const void *data) {}

void ElemWidget::changeTexture(const void *data) {}


void ElemWidget::setWidth(int width) {
    width_ = width;
}

void ElemWidget::setHeigth(int height) {
    height_ = height;
}

double ElemWidget::getPosX() const {
    return posX_;
}

double ElemWidget::getPosY() const {
    return posY_;
}

double ElemWidget::getWidth() const {
    return width_;
}

double ElemWidget::getHeigth() const {
    return height_;
}

ElemWidget::~ElemWidget() {
    delete texture_;
}

}
