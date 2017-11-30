#ifndef IRENDERABLE_HPP_INCLUDED
#define IRENDERABLE_HPP_INCLUDED

#include "IObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

class IRenderable : virtual public IObject
{
public:
    IRenderable() {}
    virtual ~IRenderable() {}

    virtual void render(sf::RenderTarget &target, float alpha) {}
    virtual void renderStationary(sf::RenderTarget &target) {}
};

#endif // IRENDERABLE_HPP_INCLUDED
