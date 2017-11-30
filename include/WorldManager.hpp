#ifndef WORLDMANAGER_HPP
#define WORLDMANAGER_HPP

#include "World.hpp"

#include <fstream>
#include <vector>

class WorldManager
{
public:
    WorldManager();
    ~WorldManager();

    void update(float frametime);
    void render(sf::RenderTarget& target, float alpha);
    void handle(sf::Event& event);

private:
    void loadWorld();
    void loadWorldFileNames();

    std::size_t mCurrentWorld;
    std::vector<World> mWorlds;
    std::vector<std::string> mWorldFileNames;
};

#endif // WORLDMANAGER_HPP
