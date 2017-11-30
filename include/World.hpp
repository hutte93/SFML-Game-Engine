#ifndef WORLD_HPP
#define WORLD_HPP

#include "ICollideable.hpp"
#include "IRenderable.hpp"
#include "WorldObject.hpp"
#include "Player.hpp"
#include "Camera.hpp"

#include <memory>
#include <SFML/Graphics.hpp>

class World
{
public:
    World(std::string path);
    ~World();

    void update(float frametime);
    void render(sf::RenderTarget& target, float alpha);
    void handle(sf::Event& event);

private:
    bool checkCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
    void resolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
    void loadWorld(std::string path);
    template <class T>
    void removeDeadObjects(std::vector<T>& v);

    sf::Vector2f mGravity;
    sf::Vector2f mSpawnPoint;
    sf::FloatRect mBoundaries;

    std::shared_ptr<Player> mPlayer;
    std::vector<std::shared_ptr<SpriteObject>> mRenderables;
    std::vector<std::shared_ptr<ICollideable>> mCollideables;

    sf::Sprite mBackground;

    Camera mCamera;
};

#endif // WORLD_HPP
