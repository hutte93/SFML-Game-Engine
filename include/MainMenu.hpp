#ifndef MAINMENU_H
#define MAINMENU_H

#include <memory>

#include "GameState.hpp"
#include "Button.hpp"
#include "Assets.hpp"

class Button;

class MainMenu : public GameState
{
public:
    MainMenu();

    void update(Game &game, float frametime) override;
    void processEvents(Game &game) override;
    void render(Game &game, float frametime) override;

private:
    void loadAssets();

private:
    sf::Sprite mBackground;

    std::shared_ptr<Button> mStartButton;
    std::shared_ptr<Button> mEditorButton;
    std::shared_ptr<Button> mExitButton;
    std::shared_ptr<Button> mSoundButton;

};

#endif // MAINMENU_H
