#include "Button.hpp"
#include "Assets.hpp"

Button::Button(sf::Vector2f position, std::string buttonStyle, std::string text)
{
    m_bHover = false;
    m_bClick = false;

    mButtonStyle = buttonStyle;

    loadAssets();

    mButtonSprite.setPosition(position);

    mButtonText.setString(text);

    setFontColor(sf::Color::Black);
    setFontSize(25);

    mSoundHovered.setVolume(20.f);
    mSoundClicked.setVolume(100.f);
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

        if (!m_bHover)
            mSoundHovered.play();

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
    if (true == m_bHover)
    {
        if (sf::Event::MouseButtonPressed == game.event.type)
        {
            if (sf::Mouse::Left == game.event.mouseButton.button)
            {
                m_bClick = true;
                mSoundHovered.stop();
                mSoundClicked.play();
            }
        }
        else
        {
            m_bClick = false;
        }
    }
    return m_bClick;
}

void Button::render(sf::RenderWindow& window)
{
    window.draw(mButtonSprite);

    window.draw(mButtonText);
}

void Button::loadAssets()
{
    mButtonSprite.setTexture(Assets::sprites[mButtonStyle].mTexture);

    mButtonText.setFont(Assets::fonts["mario"].mFont);

    mSoundHovered.setBuffer(Assets::sounds["hovered"].mSoundBuffer);
    mSoundClicked.setBuffer(Assets::sounds["clicked"].mSoundBuffer);
}

void Button::setColor(sf::Color color)
{
    mButtonSprite.setColor(color);
}

void Button::setFontColor(sf::Color color)
{
    mButtonText.setFillColor(color);
}

void Button::setFontSize(int size)
{
    mButtonText.setCharacterSize(size);
    sf::FloatRect textRect = mButtonText.getLocalBounds();
    mButtonText.setOrigin(textRect.left + textRect.width / 2.f,
        textRect.top + textRect.height / 2.f);

    mButtonText.setPosition(Assets::sprites[mButtonStyle].mTexture.getSize().x / 2.f + mButtonSprite.getPosition().x,
                            Assets::sprites[mButtonStyle].mTexture.getSize().y / 4.f + mButtonSprite.getPosition().y);

    mButtonSprite.setTextureRect(sf::IntRect(0,0,Assets::sprites[mButtonStyle].mTexture.getSize().x,Assets::sprites[mButtonStyle].mTexture.getSize().y / 2));
}
