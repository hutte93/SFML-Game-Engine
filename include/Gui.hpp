#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "Game.hpp"

class Gui
{
public:
    virtual bool onHover(Game& game) = 0;
    virtual bool onClick(Game& game) = 0;
    virtual void Render(sf::RenderWindow& window) = 0;

protected:
    bool m_bHover;
    bool m_bClick;
};

#endif // GUI_HPP_INCLUDED
