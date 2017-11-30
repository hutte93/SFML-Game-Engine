#include "Assets.hpp"

std::map<std::string, SpriteInfo> Assets::sprites;
std::map<std::string, FontInfo> Assets::fonts;

void Assets::loadAssets()
{
    sprites["MenuButton"] = SpriteInfo("assets/gfx/MenuButton.png");
    sprites["background"] = SpriteInfo("assets/gfx/Background.png");

//    // animated sprites
//    sprites["bluepeewee"] = SpriteInfo("assets/gfx/bluepeewee.png", 36, 6);
//    sprites["bluepeewee"].mHitBox = sf::FloatRect(20.f, 10.f, 24.f, 44.f);
//
//    sprites["mario"] = SpriteInfo("assets/gfx/mario2.png", 8, 8);
//    sprites["mario"].mHitBox = sf::FloatRect(2.f, 10.f, 14.f, 15.f);
//
//    sprites["bridge"] = SpriteInfo("assets/gfx/bridge.png");
//    sprites["bridge"].mHitBox = sf::FloatRect(6.f, 37.f, 140.f, 6.f);

    // fonts
    fonts["normal"] = FontInfo("assets/fnt/Purpose-normal.ttf");
}
