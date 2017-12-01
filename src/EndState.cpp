#include "EndState.hpp"

EndState::EndState()
{
    #ifdef DEBUG
        std::cout << "--> EndState" << std::endl;
    #endif // DEBUG

    loadAssets();
}

void EndState::update(Game &game, float frametime)
{

}

void EndState::processEvents(Game &game)
{

}

void EndState::render(Game &game, float frametime)
{

}

void EndState::loadAssets()
{

}
