#ifndef RESOURCES_HPP_INCLUDED
#define RESOURCES_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class Resources
{
public:
    Resources();

    static std::string getDataPath();
    static void setDataPath(std::string mainPath);

    static sf::Font& getFont(std::string name);
    static sf::Texture& getTexture(std::string name);
//    static sf::SoundBuffer& getSoundBuffer(std::string name);

private:
    static std::string m_FilePath;

    typedef std::map<std::string, sf::Font> FontMap;
    static FontMap m_Fonts;

    typedef std::map<std::string, sf::Texture> TextureMap;
    static TextureMap m_Textures;

//    typedef std::map<std::string, sf::SoundBuffer> SoundMap;
//    static SoundMap m_Sounds;
};

#endif // RESOURCES_HPP_INCLUDED
