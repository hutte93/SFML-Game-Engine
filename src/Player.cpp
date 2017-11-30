#include "Player.hpp"
#include "Direction.hpp"

Player::Player(SpriteInfo &info, sf::Vector2f pos) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos)
{
    mRunSpeed = 2.f;
    mJumpSpeed = 4.f;
    mGrounded = false;
    mDirection = Direction::STILL_LEFT;
}

Player::~Player()
{
    //dtor
}

void Player::update(float frametime)
{
    SpriteObject::update();

    mOldPhysicsPosition = mPhysicsPosition;
    mPhysicsPosition += mVelocity;

    /// animations
    if (false == mGrounded)
    {
        if (Direction::LEFT == mDirection)
            //setFrameLoop(33, 33);
            setFrameLoop(7, 7);
        else if (Direction::STILL_LEFT == mDirection)
            //setFrameLoop(35, 35);
            setFrameLoop(7, 7);

        else if (Direction::RIGHT == mDirection)
            //setFrameLoop(30, 30);
            setFrameLoop(7, 7);
        else if (Direction::STILL_RIGHT == mDirection)
            //setFrameLoop(32, 32);
            setFrameLoop(7, 7);
    }
    else if (true == mGrounded)
    {
        if (Direction::LEFT == mDirection)
            //setFrameLoop(12, 17);
            setFrameLoop(0, 1);
        else if (Direction::STILL_LEFT == mDirection)
            //setFrameLoop(0, 5);
            setFrameLoop(0, 0);

        else if (Direction::RIGHT == mDirection)
            //setFrameLoop(18, 23);
            setFrameLoop(0, 1);
        else if (Direction::STILL_RIGHT == mDirection)
            //setFrameLoop(6, 11);
            setFrameLoop(0, 0);
    }
}

void Player::handle(sf::Event &event)
{
    if (sf::Event::KeyPressed == event.type)
    {
        if (sf::Keyboard::Space == event.key.code && mGrounded)
        {
            mVelocity.y = -mJumpSpeed;
            mGrounded = false;
        }
        if (sf::Keyboard::A == event.key.code)
        {
            mVelocity.x = -mRunSpeed;
            mDirection = Direction::LEFT;
        }
        else if (sf::Keyboard::D == event.key.code)
        {
            mVelocity.x = mRunSpeed;
            mDirection = Direction::RIGHT;
        }
    }
    else if (sf::Event::KeyReleased == event.type)
    {
        if (sf::Keyboard::A == event.key.code)
        {
            mVelocity.x = 0.f;
            mDirection = Direction::STILL_LEFT;
        }
        else if (sf::Keyboard::D == event.key.code)
        {
            mVelocity.x = 0.f;
            mDirection = Direction::STILL_RIGHT;
        }
    }
}

void Player::render(sf::RenderTarget &target, float alpha)
{
    SpriteObject::render(target, alpha);

    mRenderPosition = mPhysicsPosition;/* * alpha + mOldPhysicsPosition * (1.f - alpha);*/
}

void Player::respawn(sf::Vector2f pos)
{
    mOldPhysicsPosition = pos;
    mPhysicsPosition = pos;
    mRenderPosition = pos;
    mVelocity = sf::Vector2f();
    mAlive = true;
}

bool Player::onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop)
{
    if (true == object.lock()->isStatic())
    {
        mGrounded = true;
    }

    return true;
}
