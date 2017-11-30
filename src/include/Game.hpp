#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

#include "GameState.hpp"

class GameState;
class MainMenu;
class PlayState;
class EndState;

class Game
{
public:
    enum class gameState
    {
        MAINMENU, PLAYSTATE, ENDSTATE
    };

    Game(int width, int height, std::string title);
    ~Game();

    void run();
    void changeState(gameState newState);

public:
    sf::RenderWindow window;
    sf::Event event;

private:
    void update();
    void processEvents();
    void render();

    void calcFrametime();

private:
    sf::Clock *pClock;
    float mFrametime;
    float mFPS;
    std::string mTitle;

    std::unique_ptr<GameState> mCurrentState;
};

#endif // GAME_H
