#include "MainMenu.hpp"
#include "Resources.hpp"

MainMenu::MainMenu()
{
    loadAssets();
}

void MainMenu::update(Game &game)
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
    window.draw(m_background);
    mStartButton->Render(window);
    mHelpButton->Render(window);
    mExitButton->Render(window);
}

void MainMenu::loadAssets()
{
    m_background.setTexture(Resources::getTexture("Background.png"));

    mStartButton = std::make_shared<Button> (sf::Vector2f(480.f - 150.f, 150.f), "Start");
    mHelpButton  = std::make_shared<Button> (sf::Vector2f(480.f - 150.f, 250.f), "Help");
    mExitButton  = std::make_shared<Button> (sf::Vector2f(480.f - 150.f, 350.f), "Exit");
}
