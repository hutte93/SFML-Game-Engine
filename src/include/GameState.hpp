#ifndef GAMESTATE_HPP_INCLUDED
#define GAMESTATE_HPP_INCLUDED

#include "Game.hpp"

class Game;

class GameState
{
public:
    GameState() {};

    virtual void update(Game &game) = 0;
    virtual void processEvents(Game &game) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
};

#endif // GAMESTATE_HPP_INCLUDED
