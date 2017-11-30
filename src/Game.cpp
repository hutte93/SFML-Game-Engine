#include "Game.hpp"
#include "MainMenu.hpp"
#include "PlayState.hpp"
#include "EndState.hpp"

Game::Game(int width, int height, std::string title)
    : window(sf::VideoMode(width, height), title, sf::Style::Close)
{
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);
    changeState(Game::gameState::MAINMENU);

    pClock = new sf::Clock;
    pClock->restart();

    mTitle = title;
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

        update();
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
            break;
        case gameState::PLAYSTATE:
            mCurrentState = std::move(std::unique_ptr<PlayState>(new PlayState));
            break;
        case gameState::ENDSTATE:
            mCurrentState = std::move(std::unique_ptr<EndState>(new EndState));
            break;
        default:
            throw std::runtime_error("Unable to change gamestate!");
    }
}

void Game::update()
{
    mCurrentState->update(*this);
}

void Game::processEvents()
{
    while (window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            window.close();
        }
    }

    mCurrentState->processEvents(*this);
}

void Game::render()
{
    window.clear(sf::Color(120, 120, 120));

    mCurrentState->render(window);

    window.display();
}

void Game::calcFrametime()
{
    mFrametime = pClock->getElapsedTime().asSeconds();
    mFPS = 1.f / mFrametime;

    std::stringstream ss;
    ss << mFPS;
    std::string title = mTitle + " @ " + ss.str() + " FPS";

    window.setTitle(title);

    pClock->restart();
}
