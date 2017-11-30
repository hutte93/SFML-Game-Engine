#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "FontInfo.hpp"
#include "SpriteInfo.hpp"

#include <map>

struct Assets
{
    static void loadAssets();

    static std::map<std::string, SpriteInfo> sprites;
    static std::map<std::string, FontInfo> fonts;
};

#endif // ASSETS_HPP
