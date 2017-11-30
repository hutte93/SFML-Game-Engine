#ifndef PLAYSTATE_HPP_INCLUDED
#define PLAYSTATE_HPP_INCLUDED

#include <memory>

#include "GameState.hpp"

class PlayState : public GameState
{
public:
    PlayState();

    void update(Game &game) override;
    void processEvents(Game &game) override;
    void render(sf::RenderWindow &window) override;

private:
    void loadAssets();
};

#endif // PLAYSTATE_HPP_INCLUDED
