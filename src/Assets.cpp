#include "Assets.hpp"

std::map<std::string, SpriteInfo> Assets::sprites;
std::map<std::string, FontInfo> Assets::fonts;
std::map<std::string, SoundInfo> Assets::sounds;

void Assets::loadAssets()
{
    /// sprites
    sprites["MenuButton"] = SpriteInfo("assets/gfx/MenuButton.png");
    sprites["PauseButton"] = SpriteInfo("assets/gfx/PauseButton.png");
    sprites["MenuBackground"] = SpriteInfo("assets/gfx/MenuBackground.png");
    sprites["GameBackground"] = SpriteInfo("assets/gfx/background.png");

    sprites["grass_left"] = SpriteInfo("assets/gfx/grass_left.png");
    sprites["grass_mid"] = SpriteInfo("assets/gfx/grass_mid.png");
    sprites["grass_right"] = SpriteInfo("assets/gfx/grass_right.png");
    sprites["grass_down_right"] = SpriteInfo("assets/gfx/grass_down_right.png");
    sprites["grass_down_left"] = SpriteInfo("assets/gfx/grass_down_left.png");
    sprites["dirt_left"] = SpriteInfo("assets/gfx/dirt_left.png");
    sprites["dirt_mid"] = SpriteInfo("assets/gfx/dirt_mid.png");
    sprites["dirt_right"] = SpriteInfo("assets/gfx/dirt_right.png");

    sprites["mario"] = SpriteInfo("assets/gfx/mario.png", 8, 8);

    sprites["grassblock"] = SpriteInfo("assets/gfx/grass_block.png");
    sprites["tilegrassblock"] = SpriteInfo("assets/gfx/grass_block_tileable.png");
    sprites["tallrock"] = SpriteInfo("assets/gfx/tall_rock.png");
    sprites["ladder"] = SpriteInfo("assets/gfx/ladder.png");
    sprites["cloud"] = SpriteInfo("assets/gfx/cloud.png");

    sprites["bluepeewee"] = SpriteInfo("assets/gfx/bluepeewee.png", 36, 6);
    sprites["bluepeewee"].mHitBox = sf::FloatRect(20.f, 10.f, 24.f, 44.f);
    sprites["bridge"] = SpriteInfo("assets/gfx/bridge.png");
    sprites["bridge"].mHitBox = sf::FloatRect(6.f, 37.f, 140.f, 6.f);

    /// fonts
    fonts["normal"] = FontInfo("assets/fnt/Purpose-normal.ttf");
    fonts["mario"] = FontInfo("assets/fnt/supermario.ttf");

    /// sounds
    sounds["menu"] = SoundInfo("assets/snd/music/smw_menu.wav");
    sounds["hovered"] = SoundInfo("assets/snd/select2.wav");
    sounds["clicked"] = SoundInfo("assets/snd/click.wav");
    sounds["jump"] = SoundInfo("assets/snd/smw_jump.wav");
    sounds["coin"] = SoundInfo("assets/snd/smw_coin.wav");
    sounds["dead"] = SoundInfo("assets/snd/smw_lost_a_life.wav");
}
