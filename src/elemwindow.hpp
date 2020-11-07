#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

//#include <SFML/Graphics.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ElemWindow {
    //sf::Texture* texture_;
    //sf::Sprite* sprite_;
    int width_;
    int height_;

public:
    ElemWindow(int width, int height);
    virtual void draw();
    virtual void update();
    virtual bool isHidden() const;

    virtual bool testClick() const;
    virtual void onClick();
    virtual bool testEvent() const;
    virtual void handleEvent();

    virtual void onKey(int key);

    virtual void onMove();
    virtual void onOpen();
    virtual void onClose();
    virtual void onFocus();
    virtual void onResize();

    /// Setters
    void setWidth(int width);
    void setHeigth(int height);

    virtual ~ElemWindow();
};

#endif // SIMPLEWINDOW_H
