#include "Resources.hpp"

std::string Resources::m_FilePath = "assets/";
Resources::FontMap Resources::m_Fonts;
Resources::TextureMap Resources::m_Textures;
//Resources::SoundMap Resources::m_Sounds;

Resources::Resources()
{

}

std::string Resources::getDataPath()
{
    return m_FilePath;
}

void Resources::setDataPath(std::string mainPath)
{
    m_FilePath = mainPath;
}

sf::Font& Resources::getFont(std::string name)
{
    FontMap::iterator it = m_Fonts.find(name);
    if (it == m_Fonts.end())
    {
        sf::Font& font = m_Fonts[name];
        font.loadFromFile(m_FilePath + "fnt/" + name);
        return font;
    }
    return it->second;
}

sf::Texture& Resources::getTexture(std::string name)
{
    TextureMap::iterator it = m_Textures.find(name);
    if (it == m_Textures.end())
    {
        sf::Texture& texture = m_Textures[name];
        texture.loadFromFile(m_FilePath + "gfx/" + name);
        return texture;
    }
    return it->second;
}

//sf::SoundBuffer& Resources::getSoundBuffer(std::string name)
//{
//    SoundMap::iterator it = m_Sounds.find(name);
//    if (it == m_Sounds.end())
//    {
//        sf::SoundBuffer& sound = m_Sounds[name];
//        sound.loadFromFile(m_FilePath + "snd/" + name);
//        return sound;
//    }
//    return it->second;
//}
