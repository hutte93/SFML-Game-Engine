#include "PlayState.hpp"
#include "WorldManager.hpp"

WorldManager *pWorldMgr;

PlayState::PlayState()
{
    #ifdef DEBUG
        std::cout << "--> PlayState" << std::endl;
    #endif // DEBUG

    loadAssets();

    pWorldMgr = new WorldManager;
}

void PlayState::update(Game &game, float frametime)
{
    pWorldMgr->update(frametime);
}

void PlayState::processEvents(Game &game)
{
    pWorldMgr->handle(game.event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        pWorldMgr->resetView(game.window);
        game.changeState(Game::gameState::MAINMENU);
    }

    if (sf::Joystick::isButtonPressed(0, sf::Joystick::PovX))
    {
        pWorldMgr->resetView(game.window);
        game.changeState(Game::gameState::MAINMENU);
    }
}

void PlayState::render(Game &game, float frametime)
{
    pWorldMgr->render(game.window, frametime);
}

void PlayState::loadAssets()
{
}
