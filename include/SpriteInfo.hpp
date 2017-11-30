#ifndef SPRITEINFO_HPP_INCLUDED
#define SPRITEINFO_HPP_INCLUDED

#include <SFML/Graphics.hpp>

struct SpriteInfo
{
    SpriteInfo() {}
    SpriteInfo(std::string path, int frames = 1, int framesPerRow = 1) :
        mFrames(frames),
        mFramesPerRow(framesPerRow)
    {
        mTexture.loadFromFile(path);
        mFrameDim = sf::Vector2f(mTexture.getSize().x / mFramesPerRow, mTexture.getSize().y / (mFrames / mFramesPerRow));
        mHitBox = sf::FloatRect(0.f, 0.f, mFrameDim.x, mFrameDim.y);
    }

    sf::Texture mTexture;
    sf::Vector2f mFrameDim;
    sf::FloatRect mHitBox;

    int mFrames;
    int mFramesPerRow;
};

#endif // SPRITEINFO_HPP_INCLUDED
