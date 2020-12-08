#include "elemwidget.hpp"

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
ElemWidget::ElemWidget() :
    texture_(nullptr),
    isHidden_(false) {}

ElemWidget::ElemWidget(const GLfloat *vertices, const char *texPath) :
    texture_(new Texture(vertices, texPath)),
    isHidden_(false) {}

// Draw texture if exists
void ElemWidget::draw() {
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

bool ElemWidget::testEvent() const {
    return false;
}

void ElemWidget::handleEvent() {}

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

ElemWidget::~ElemWidget() {
    delete texture_;
}
