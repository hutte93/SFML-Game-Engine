#ifndef WORLDOBJECT_HPP
#define WORLDOBJECT_HPP

#include "SpriteObject.hpp"
#include "ICollideable.hpp"

class WorldObject : public SpriteObject, public ICollideable
{
public:
    WorldObject(SpriteInfo &info, sf::Vector2f pos, bool _static = false);
    ~WorldObject();

    void update();
    void render(sf::RenderTarget &target, float alpha);
};

#endif // WORLDOBJECT_HPP
