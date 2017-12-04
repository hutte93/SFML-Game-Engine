#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

#include "Constants.hpp"
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
        MAINMENU, PLAYSTATE, EDITORSTATE
    };

    Game(std::string title);
    ~Game();

    void run();
    void changeState(gameState newState);
    void toggleSound();

public:
    sf::RenderWindow window;
    sf::Event event;

private:
    void update(float frametime);
    void processEvents();
    void render();

    void calcFrametime();

private:
    sf::Clock *pClock;
    float mFrametime;
    float mFPS;
    std::string mTitle;

    std::unique_ptr<GameState> mCurrentState;

    sf::Sound mSoundMenu;
    bool mIsPlayingSound;
};

#endif // GAME_H
