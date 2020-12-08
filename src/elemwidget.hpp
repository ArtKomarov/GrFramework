#ifndef ELEMWIDGET_H
#define ELEMWIDGET_H

//#include <SFML/Graphics.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "texture.hpp"

class ElemWidget {
    Texture* texture_;

    bool isHidden_;

    int posX;
    int poxY;
    int width_;
    int height_;

protected:
    /// Texture functions
    void texSetTransformColor(const glm::vec3 &vec);

    void texSetTransformTexCoords(const glm::mat2 &matrix);

    void texSetTransformPos(const glm::mat4& matrix);
public:
    ElemWidget();
    ElemWidget(const GLfloat *vertices, const char *texPath);

    virtual void draw();
    virtual void update();
    virtual bool isHidden() const;

    virtual bool testClick() const;
    virtual bool testEvent() const;

    virtual void handleEvent();

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
    void setWidth(int width);
    void setHeigth(int height);

    virtual ~ElemWidget();
};

#endif // ELEMWIDGET_H
