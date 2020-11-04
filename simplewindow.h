#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <SFML/Graphics.hpp>

class SimpleWindow {
    sf::Texture* texture_;
    sf::Sprite* sprite_;

public:
    SimpleWindow();
    virtual void draw(sf::RenderWindow &target) const;
    virtual bool isHidden() const;

    virtual bool testClick(const sf::Vector2f& cords) const;
    virtual void onClick(const sf::Vector2f& cords);
    virtual bool testEvent(const sf::Event& event) const;
    virtual void handleEvent(const sf::Event& event);

    virtual void onKey(int key);

    virtual void onMove();
    virtual void onOpen();
    virtual void onClose();
    virtual void onFocus();
    virtual void onResize();

    ~SimpleWindow();
};

#endif // SIMPLEWINDOW_H
