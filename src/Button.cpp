#include "Button.hpp"
#include "Resources.hpp"

Button::Button(sf::Vector2f position, std::string text)
{
    m_bHover = false;
    m_bClick = false;

    loadTexture();

    mButtonSprite.setPosition(position);
    mButtonText.setString(text);

    sf::FloatRect textRect = mButtonText.getLocalBounds();
    mButtonText.setOrigin(textRect.left + textRect.width / 2.f,
        textRect.top + textRect.height / 2.f);
    mButtonText.setPosition(Resources::getTexture("MenuButton.png").getSize().x / 2.f + mButtonSprite.getPosition().x,
        Resources::getTexture("MenuButton.png").getSize().y / 4.f + mButtonSprite.getPosition().y
    );

    mButtonSprite.setTextureRect(sf::IntRect(0,0,Resources::getTexture("MenuButton.png").getSize().x,Resources::getTexture("MenuButton.png").getSize().y / 2));

    mButtonText.setFillColor(sf::Color::Black);
    mButtonText.setCharacterSize(30);
}

Button::~Button()
{

}

bool Button::onHover(Game& game)
{
    // check if the mouse is hovering on the button
    if (sf::Mouse::getPosition(game.window).x >= mButtonSprite.getPosition().x &&
        sf::Mouse::getPosition(game.window).x < mButtonSprite.getPosition().x + mButtonSprite.getGlobalBounds().width &&
        sf::Mouse::getPosition(game.window).y >= mButtonSprite.getPosition().y &&
        sf::Mouse::getPosition(game.window).y < mButtonSprite.getPosition().y + mButtonSprite.getGlobalBounds().height)
    {
        mButtonSprite.setTextureRect(sf::IntRect(0, mButtonSprite.getGlobalBounds().height, mButtonSprite.getGlobalBounds().width, mButtonSprite.getGlobalBounds().height));
        m_bHover = true;
    }

    // check if the mouse isn't hovering on the button
    if (sf::Mouse::getPosition(game.window).x < mButtonSprite.getPosition().x ||
        sf::Mouse::getPosition(game.window).x > mButtonSprite.getPosition().x + mButtonSprite.getGlobalBounds().width ||
        sf::Mouse::getPosition(game.window).y < mButtonSprite.getPosition().y ||
        sf::Mouse::getPosition(game.window).y > mButtonSprite.getPosition().y + mButtonSprite.getGlobalBounds().height)
    {
        mButtonSprite.setTextureRect(sf::IntRect(0, 0, mButtonSprite.getGlobalBounds().width, mButtonSprite.getGlobalBounds().height));
        m_bHover = false;
    }

    return m_bHover;
}

bool Button::onClick(Game& game)
{
    // check if button is hovered
    if (m_bHover == true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            m_bClick = true;
    }
    else
    {
        m_bClick = false;
    }

    return m_bClick;
}

void Button::Render(sf::RenderWindow& window)
{
    window.draw(mButtonSprite);
    window.draw(mButtonText);
}

void Button::loadTexture()
{
    mButtonSprite.setTexture(Resources::getTexture("MenuButton.png"));

    mButtonText.setFont(Resources::getFont("Purpose-normal.ttf"));
}

void Button::setColor(sf::Color color)
{
    mButtonSprite.setColor(color);
}
