#include "WorldObject.hpp"

WorldObject::WorldObject(SpriteInfo& info, sf::Vector2f pos, bool _static) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos, _static)
{
    //ctor
}

WorldObject::~WorldObject()
{
    //dtor
}

void WorldObject::update()
{
    SpriteObject::update();

    mOldPhysicsPosition = mPhysicsPosition;
    mPhysicsPosition += mVelocity;
}

void WorldObject::render(sf::RenderTarget& target, float alpha)
{
    SpriteObject::render(target, alpha);

    mRenderPosition = mPhysicsPosition*alpha + mOldPhysicsPosition*(1.f - alpha);
}
