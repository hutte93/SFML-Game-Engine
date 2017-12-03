#include "MainMenu.hpp"

MainMenu::MainMenu()
{
    #ifdef DEBUG
        std::cout << "--> MainMenuState" << std::endl;
    #endif // DEBUG

    loadAssets();

    /// Auto-Scale Background
    float scaleX = SCREEN_WIDTH / Assets::sprites["MenuBackground"].mTexture.getSize().x;
    float scaleY = SCREEN_HEIGHT / Assets::sprites["MenuBackground"].mTexture.getSize().y;
    mBackground.setScale(scaleX, scaleY);

    mStartButton->setColor(sf::Color::Green);
    mHelpButton->setColor(sf::Color::Yellow);
    mExitButton->setColor(sf::Color::Red);
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

void MainMenu::render(Game &game, float frametime)
{
    game.window.draw(mBackground);
    mStartButton->render(game.window);
    mHelpButton->render(game.window);
    mExitButton->render(game.window);
}

void MainMenu::loadAssets()
{
    mBackground.setTexture(Assets::sprites["MenuBackground"].mTexture);

    mStartButton = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 150.f), "MenuButton", "Start");
    mHelpButton  = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 250.f), "MenuButton", "Help");
    mExitButton  = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 350.f), "MenuButton", "Quit");
}
