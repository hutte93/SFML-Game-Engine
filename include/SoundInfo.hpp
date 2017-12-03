#ifndef SOUNDINFO_HPP_INCLUDED
#define SOUNDINFO_HPP_INCLUDED

#include <SFML/Audio/SoundBuffer.hpp>

struct SoundInfo
{
    SoundInfo() {}
    SoundInfo(std::string path)
    {
        mSoundBuffer.loadFromFile(path);
    }

    sf::SoundBuffer mSoundBuffer;
};

#endif // SOUNDINFO_HPP_INCLUDED
