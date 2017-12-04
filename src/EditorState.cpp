#include "EditorState.hpp"

EditorState::EditorState()
{
    #ifdef DEBUG
        std::cout << "--> EditorState" << std::endl;
    #endif // DEBUG

    loadAssets();
}

void EditorState::update(Game &game, float frametime)
{

}

void EditorState::processEvents(Game &game)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        game.changeState(Game::gameState::MAINMENU);
    }

    if (sf::Joystick::isButtonPressed(0, sf::Joystick::PovX))
    {
        game.changeState(Game::gameState::MAINMENU);
    }
}

void EditorState::render(Game &game, float frametime)
{

}

void EditorState::loadAssets()
{

}
