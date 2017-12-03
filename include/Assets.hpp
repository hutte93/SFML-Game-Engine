#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "FontInfo.hpp"
#include "SpriteInfo.hpp"
#include "SoundInfo.hpp"

#include <map>
#include <string>

struct Assets
{
    static void loadAssets();

    static std::map<std::string, SpriteInfo> sprites;
    static std::map<std::string, FontInfo> fonts;
    static std::map<std::string, SoundInfo> sounds;
};

#endif // ASSETS_HPP
