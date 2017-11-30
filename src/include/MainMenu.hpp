#ifndef MAINMENU_H
#define MAINMENU_H

#include <memory>

#include "GameState.hpp"
#include "Button.hpp"

class Button;

class MainMenu : public GameState
{
public:
    MainMenu();

    void update(Game &game) override;
    void processEvents(Game &game) override;
    void render(sf::RenderWindow &window) override;

private:
    void loadAssets();

private:
    sf::Sprite m_background;

    std::shared_ptr<Button> mStartButton;
    std::shared_ptr<Button> mHelpButton;
    std::shared_ptr<Button> mExitButton;

};

#endif // MAINMENU_H
