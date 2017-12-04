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
    mEditorButton->setColor(sf::Color::Yellow);
    mExitButton->setColor(sf::Color::Red);
}

void MainMenu::update(Game &game, float frametime)
{
    mStartButton->onHover(game);
    mEditorButton->onHover(game);
    mExitButton->onHover(game);
    mSoundButton->onHover(game);
}

void MainMenu::processEvents(Game &game)
{
    /// Check for Button-Clicks
    if (true == mStartButton->onClick(game))
    {
        game.changeState(Game::gameState::PLAYSTATE);
    }
    else if (true == mEditorButton->onClick(game))
    {
        game.changeState(Game::gameState::EDITORSTATE);
    }
    else if (true == mExitButton->onClick(game))
    {
        game.window.close();
    }
    else if (true == mSoundButton->onClick(game))
    {
        game.toggleSound();
    }

    /// Check if Key is released
    if (sf::Event::KeyReleased == game.event.type)
    {
        if (sf::Keyboard::F1 == game.event.key.code)
        {
            game.toggleSound();
        }
    }
}

void MainMenu::render(Game &game, float frametime)
{
    game.window.draw(mBackground);
    mStartButton->render(game.window);
    mEditorButton->render(game.window);
    mExitButton->render(game.window);
    mSoundButton->render(game.window);
}

void MainMenu::loadAssets()
{
    mBackground.setTexture(Assets::sprites["MenuBackground"].mTexture);

    mStartButton = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 150.f), "MenuButton", "Start");
    mEditorButton  = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 250.f), "MenuButton", "Editor");
    mExitButton  = std::make_shared<Button> (sf::Vector2f(SCREEN_WIDTH / 2 - Assets::sprites["MenuButton"].mTexture.getSize().x / 2, 350.f), "MenuButton", "Quit");

    mSoundButton = std::make_shared<Button> (sf::Vector2f(0, SCREEN_HEIGHT - Assets::sprites["SoundButton"].mTexture.getSize().y / 2), "SoundButton");
}
