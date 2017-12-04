#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include <SFML/System/Time.hpp>

#define DEBUG

const float SCREEN_WIDTH = 960;
const float SCREEN_HEIGHT = 540;
const float FPS = 120;

const sf::Time UPDATE_STEP = sf::seconds(1.f / FPS);

#endif // CONSTANTS_HPP_INCLUDED
