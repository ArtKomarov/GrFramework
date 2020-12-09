#ifndef ELEMWIDGET_H
#define ELEMWIDGET_H

//#include <SFML/Graphics.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "texture.hpp"
#include "event.hpp"

namespace GrFramework {

class ElemWidget {
    Texture* texture_;

    bool isHidden_;

    double posX_;
    double posY_;
    double width_;
    double height_;

protected:
    /// Texture functions
    void texSetTransformColor(const glm::vec3 &vec);

    void texSetTransformTexCoords(const glm::mat2 &matrix);

    void texSetTransformPos(const glm::mat4& matrix);
public:
    ElemWidget(double posX, double posY, double width, double height);
    ElemWidget(const GLfloat *vertices, const char *texPath);

    virtual void draw() const;
    virtual void update();
    virtual bool isHidden() const;

    virtual bool testClick() const;
    virtual bool testEvent(const Event &event) const;

    virtual void processEvent(const Event &event);

    /// Reactions on events
    virtual void onClick();
    virtual void onRelease();
    virtual void onKey(int key);
    virtual void onMove();
    virtual void onOpen();
    virtual void onClose();
    virtual void onFocus();
    virtual void onResize();

    /// Actions
    virtual void changeColor   (const void *data = nullptr);
    virtual void changePos     (const void *data = nullptr);
    virtual void changeTexture (const void *data = nullptr);


    /// Setters
    void setWidth (int width);
    void setHeigth(int height);

    /// Getters
    double getPosX  () const;
    double getPosY  () const;
    double getWidth () const;
    double getHeigth() const;

    virtual ~ElemWidget();
};

}

#endif // ELEMWIDGET_H
