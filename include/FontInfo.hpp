#ifndef FONTINFO_HPP_INCLUDED
#define FONTINFO_HPP_INCLUDED

#include <SFML/Graphics.hpp>

struct FontInfo
{
    FontInfo() {}
    FontInfo(std::string path)
    {
        mFont.loadFromFile(path);
    }

    sf::Font mFont;
};

#endif // FONTINFO_HPP_INCLUDED
