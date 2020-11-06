#include "simplewindow.h"

SimpleWindow::SimpleWindow() {

}

void SimpleWindow::draw(sf::RenderWindow &target) const {
    target.draw(*sprite_);
}

bool SimpleWindow::isHidden() const
{

}

bool SimpleWindow::testClick(const sf::Vector2f &cords) const
{

}

void SimpleWindow::onClick(const sf::Vector2f &cords)
{

}

bool SimpleWindow::testEvent(const sf::Event &event) const
{

}

void SimpleWindow::handleEvent(const sf::Event &event)
{

}

void SimpleWindow::onKey(int key)
{

}

void SimpleWindow::onMove()
{

}

void SimpleWindow::onOpen()
{

}

void SimpleWindow::onClose()
{

}

void SimpleWindow::onFocus()
{

}

void SimpleWindow::onResize()
{

}

SimpleWindow::~SimpleWindow()
{

}
