#include "Player.hpp"
#include "Direction.hpp"
#include <iostream>

Player::Player(SpriteInfo& info, sf::Vector2f pos) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos)
{
    mRunSpeed = 2.f;
    mJumpSpeed = 4.f;
    mGrounded = false;
    mDirection = Direction::STILL_LEFT;
    mOldDirection = mDirection;

    mSoundJump.setBuffer(Assets::sounds["jump"].mSoundBuffer);

    /// Auto-Set Hitbox
    float scaleX = 2.f;
    float scaleY = 2.f;
    mHitBox = sf::FloatRect(2.f * scaleX, 3.f * scaleX, 14.f * scaleX, 23.f * scaleY);
    getSprite().setScale(scaleX, scaleY);
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

    // animations
    if (false == mGrounded) // above ground
    {
        if (mDirection == Direction::LEFT)
            setFrameLoop(5, 5);
        else if (mDirection == Direction::STILL_LEFT)
            setFrameLoop(5, 5);

        else if (mDirection == Direction::RIGHT)
            setFrameLoop(7, 7);
        else if (mDirection == Direction::STILL_RIGHT)
            setFrameLoop(7, 7);
    }
    else if (true == mGrounded) // walking on ground
    {
        if (mDirection == Direction::LEFT)
            setFrameLoop(2, 3);
        else if (mDirection == Direction::STILL_LEFT)
            setFrameLoop(2, 2);

        else if (mDirection == Direction::RIGHT)
            setFrameLoop(0, 1);
        else if (mDirection == Direction::STILL_RIGHT)
            setFrameLoop(0, 0);
    }
}

void Player::handle(sf::Event& event)
{
    /// Keyboard Events
    if (false == sf::Joystick::isConnected(0))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space && mGrounded)
            {
                mVelocity.y = -mJumpSpeed;
                mGrounded = false;
                mSoundJump.play();
            }
            if (event.key.code == sf::Keyboard::A)
            {
                mVelocity.x = -mRunSpeed;
                mDirection = Direction::LEFT;
            }
            else if (event.key.code == sf::Keyboard::D)
            {
                mVelocity.x = mRunSpeed;
                mDirection = Direction::RIGHT;
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::A && false == sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                mVelocity.x = 0.f;
                mDirection = Direction::STILL_LEFT;
            }
            else if (event.key.code == sf::Keyboard::D && false == sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                mVelocity.x = 0.f;
                mDirection = Direction::STILL_RIGHT;
            }
        }
    }

    /// Joystick Events
    else if (true == sf::Joystick::isConnected(0))
    {
        /// Jumping
        if (sf::Joystick::isButtonPressed(0, sf::Joystick::X) && mGrounded)
        {
            mVelocity.y = -mJumpSpeed;
            mGrounded = false;
            mSoundJump.play();
        }

        /// Movement
        if (event.joystickMove.axis == sf::Joystick::X)
        {
            if (-75 > event.joystickMove.position)
            {
                mVelocity.x = -mRunSpeed;
                mDirection = Direction::LEFT;
                mOldDirection = mDirection;
            }
            else if (75 < event.joystickMove.position)
            {
                mVelocity.x = mRunSpeed;
                mDirection = Direction::RIGHT;
                mOldDirection = mDirection;
            }

            /// Stop the Movement of the Player
            else if (true == mGrounded)
            {
                mVelocity.x = 0.f;

                if (mOldDirection == Direction::LEFT)
                    mDirection = Direction::STILL_LEFT;
                else if (mOldDirection == Direction::RIGHT)
                    mDirection = Direction::STILL_RIGHT;

                mOldDirection = mDirection;
            }
        }
    }
}

void Player::render(sf::RenderTarget& target, float alpha)
{
    SpriteObject::render(target, alpha);

    mRenderPosition = mPhysicsPosition* alpha + mOldPhysicsPosition * (1.f - alpha);
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
    if (object.lock()->isStatic())
        mGrounded = true;

    return true;
}
