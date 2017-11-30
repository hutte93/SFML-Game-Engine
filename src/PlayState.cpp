#include "PlayState.hpp"

PlayState::PlayState()
{
    loadAssets();
}

void PlayState::update(Game &game, float frametime)
{
    #ifdef DEBUG
        float fps = 1.f / frametime;
        std::cout << "fps: " << fps << std::endl;
    #endif
}

void PlayState::processEvents(Game &game)
{

}

void PlayState::render(sf::RenderWindow &window)
{

}

void PlayState::loadAssets()
{

}
