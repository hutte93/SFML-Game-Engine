#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Gui.hpp"

class Gui;
class Game;

class Button : public Gui
{
public:
    Button(sf::Vector2f position, std::string text);
    ~Button();

    bool onHover(Game& game) override;
    bool onClick(Game& game) override;

    void render(sf::RenderWindow& window) override;
    void loadTexture();
    void setColor(sf::Color color);

private:
    sf::Sprite mButtonSprite;
    sf::Text   mButtonText;
};

#endif // BUTTON_HPP_INCLUDED
