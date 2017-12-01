#ifndef ENDSTATE_HPP_INCLUDED
#define ENDSTATE_HPP_INCLUDED

#include <memory>

#include "GameState.hpp"

class EndState : public GameState
{
public:
    EndState();

    void update(Game &game, float frametime) override;
    void processEvents(Game &game) override;
    void render(Game &game, float frametime) override;

private:
    void loadAssets();
};

#endif // ENDSTATE_HPP_INCLUDED
