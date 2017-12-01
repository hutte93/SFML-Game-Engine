#ifndef PLAYSTATE_HPP_INCLUDED
#define PLAYSTATE_HPP_INCLUDED

#include <memory>

#include "GameState.hpp"

class PlayState : public GameState
{
public:
    PlayState();

    void update(Game &game, float frametime) override;
    void processEvents(Game &game) override;
    void render(Game &game, float frametime) override;

private:
    void loadAssets();

private:
    sf::Sprite mBackground;
};

#endif // PLAYSTATE_HPP_INCLUDED
