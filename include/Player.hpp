#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SpriteObject.hpp"
#include "ICollideable.hpp"

#include <SFML/Graphics.hpp>

class Player : public SpriteObject, public ICollideable
{
public:
    Player(SpriteInfo &info, sf::Vector2f pos);
    ~Player();

    bool onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);

    void update(float frametime);
    void render(sf::RenderTarget &target, float alpha);
    void handle(sf::Event &event);

    void respawn(sf::Vector2f pos);

private:
    int mRunSpeed;
    int mJumpSpeed;
    bool mGrounded;
    std::size_t mDirection;
};

#endif // PLAYER_HPP
