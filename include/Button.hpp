#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Gui.hpp"
#include <string>
#include <SFML/Audio.hpp>

class Gui;
class Game;

class Button : public Gui
{
public:
    Button(sf::Vector2f position, std::string buttonStyle, std::string text);
    ~Button();

    bool onHover(Game& game) override;
    bool onClick(Game& game) override;

    void render(sf::RenderWindow& window) override;
    void loadAssets();
    void setColor(sf::Color color);

private:
    sf::Sprite mButtonSprite;
    sf::Text   mButtonText;

    sf::Sound  mSoundHovered;
    sf::Sound  mSoundClicked;

    std::string mButtonStyle;
};

#endif // BUTTON_HPP_INCLUDED
