#ifndef ENDSTATE_HPP_INCLUDED
#define ENDSTATE_HPP_INCLUDED

#include <memory>

#include "GameState.hpp"

class EndState : public GameState
{
public:
    EndState();

    void update(Game &game) override;
    void processEvents(Game &game) override;
    void render(sf::RenderWindow &window) override;

private:
    void loadAssets();
};

#endif // ENDSTATE_HPP_INCLUDED
