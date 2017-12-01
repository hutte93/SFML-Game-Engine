#ifndef SPRITEOBJECT_HPP
#define SPRITEOBJECT_HPP

#include "IRenderable.hpp"
#include "SpriteInfo.hpp"

#include <SFML/Graphics.hpp>

class SpriteObject : public IRenderable
{
public:
    SpriteObject(SpriteInfo &info, sf::Vector2f pos, bool parallax = false);
    virtual ~SpriteObject();

    virtual void update();
    virtual void render(sf::RenderTarget &target, float alpha);

    /// Setter
    void setRenderPosition(sf::Vector2f pos) { mRenderPosition = pos; mSprite.setPosition(pos); }
    void setFrameLoop(int start, int stop, bool loop = true);

    /// Getter
    SpriteInfo getSpriteInfo()       { return mSpriteInfo; }
    sf::Sprite &getSprite()          { return mSprite; }
    sf::Vector2f getRenderPosition() { return mRenderPosition; }
    bool isParallaxable()            { return mParallaxable; }

protected:
    SpriteInfo &mSpriteInfo;
    sf::Sprite mSprite;
    sf::Vector2f mRenderPosition;
    sf::Clock mAnimClock;

    bool mParallaxable;

    int mCurrentFrame;
    int mStartFrame;
    int mEndFrame;
    int mFrameDir;
    float mFrameDelay;
    bool mLoopAnim;
};

#endif // SPRITEOBJECT_HPP
