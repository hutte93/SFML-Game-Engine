#include "Assets.hpp"

std::map<std::string, SpriteInfo> Assets::sprites;
std::map<std::string, FontInfo> Assets::fonts;
std::map<std::string, SoundInfo> Assets::sounds;

void Assets::loadAssets()
{
    /// sprites
    sprites["MenuButton"] = SpriteInfo("assets/gfx/MenuButton.png");
    sprites["SoundButton"] = SpriteInfo("assets/gfx/sound_button_on.png");
    sprites["PauseButton"] = SpriteInfo("assets/gfx/PauseButton.png");
    sprites["MenuBackground"] = SpriteInfo("assets/gfx/MenuBackground.png");
    sprites["GameBackground"] = SpriteInfo("assets/gfx/Background.png");

    sprites["grass_left"] = SpriteInfo("assets/gfx/grass_left.png");
    sprites["grass_mid"] = SpriteInfo("assets/gfx/grass_mid.png");
    sprites["grass_right"] = SpriteInfo("assets/gfx/grass_right.png");
    sprites["grass_down_right"] = SpriteInfo("assets/gfx/grass_down_right.png");
    sprites["grass_down_left"] = SpriteInfo("assets/gfx/grass_down_left.png");
    sprites["dirt_left"] = SpriteInfo("assets/gfx/dirt_left.png");
    sprites["dirt_mid"] = SpriteInfo("assets/gfx/dirt_mid.png");
    sprites["dirt_right"] = SpriteInfo("assets/gfx/dirt_right.png");

    sprites["mario"] = SpriteInfo("assets/gfx/mario.png", 8, 8);

    sprites["cloud"] = SpriteInfo("assets/gfx/cloud.png");


    /// fonts
    fonts["mario"] = FontInfo("assets/fnt/supermario.ttf");

    /// sounds
    sounds["menu"] = SoundInfo("assets/snd/smw_menu.wav");
    sounds["hovered"] = SoundInfo("assets/snd/select2.wav");
    sounds["clicked"] = SoundInfo("assets/snd/click.wav");
    sounds["jump"] = SoundInfo("assets/snd/smw_jump.wav");
    sounds["coin"] = SoundInfo("assets/snd/smw_coin.wav");
    sounds["dead"] = SoundInfo("assets/snd/smw_lost_a_life.wav");
}
