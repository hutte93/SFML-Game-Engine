#include "MainMenu.hpp"

MainMenu::MainMenu()
{
    loadAssets();
}

void MainMenu::update(Game &game, float frametime)
{
    mStartButton->onHover(game);
    mHelpButton->onHover(game);
    mExitButton->onHover(game);
}

void MainMenu::processEvents(Game &game)
{
    if (mStartButton->onClick(game) == true)
    {
        game.changeState(Game::gameState::PLAYSTATE);
    }
    else if (mHelpButton->onClick(game) == true)
    {

    }
    else if (mExitButton->onClick(game) == true)
    {
        game.window.close();
    }
}

void MainMenu::render(sf::RenderWindow &window)
{
    window.draw(mBackground);
    mStartButton->render(window);
    mHelpButton->render(window);
    mExitButton->render(window);
}

void MainMenu::loadAssets()
{
    mBackground = sf::Sprite(Assets::sprites["background"].mTexture);

    mStartButton = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 150.f), "Start");
    mHelpButton  = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 250.f), "Help");
    mExitButton  = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 350.f), "Quit");
}
