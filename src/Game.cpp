#include "Game.hpp"
#include "MainMenu.hpp"
#include "PlayState.hpp"
#include "EndState.hpp"

Game::Game(std::string title)
    : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title, sf::Style::Close)
{
    window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);

    pClock = new sf::Clock;
    pClock->restart();

    mTitle = title;

    Assets::loadAssets();

    mSoundMenu.setBuffer(Assets::sounds["menu"].mSoundBuffer);

    changeState(Game::gameState::MAINMENU);
}

Game::~Game()
{
    delete pClock;
    pClock = nullptr;
}

void Game::run()
{
    while (true == window.isOpen())
    {
        calcFrametime();

        update(mFrametime);
        processEvents();
        render();
    }
}

void Game::changeState(gameState newState)
{
    switch (newState)
    {
        case gameState::MAINMENU:
            mCurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
            mSoundMenu.play();
            break;
        case gameState::PLAYSTATE:
            mCurrentState = std::move(std::unique_ptr<PlayState>(new PlayState));
            mSoundMenu.stop();
            break;
        case gameState::ENDSTATE:
            mCurrentState = std::move(std::unique_ptr<EndState>(new EndState));
            break;
        default:
            throw std::runtime_error("Unable to change gamestate!");
    }
}

void Game::update(float deltatime)
{
    mCurrentState->update(*this, deltatime);
}

void Game::processEvents()
{
    while (window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            mSoundMenu.stop();
            window.close();
        }

        mCurrentState->processEvents(*this);
    }
}

void Game::render()
{
    window.clear(sf::Color(120, 120, 120));

    mCurrentState->render(*this, mFrametime);

    window.display();
}

void Game::calcFrametime()
{
    mFrametime = pClock->getElapsedTime().asSeconds();

    #ifdef DEBUG
        mFPS = 1.f / mFrametime;

        std::stringstream ss;
        ss << mFPS;
        std::string title = mTitle + " @ " + ss.str() + " FPS";

        window.setTitle(title);
    #endif // DEBUG

    pClock->restart();
}
