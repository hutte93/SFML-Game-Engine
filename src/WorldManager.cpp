#include "WorldManager.hpp"

WorldManager::WorldManager() :
    mCurrentWorld(0)
{
    loadWorldFileNames();
    loadWorld();
}

WorldManager::~WorldManager()
{
    //dtor
}

void WorldManager::update(float frametime)
{
    mWorlds[mCurrentWorld].update(frametime);

//    if (mWorlds[mCurrentWorld].getBlackHole().lock()->isCollided())
//    {
//        mCurrentWorld = mWorlds[mCurrentWorld].getBlackHole().lock()->getNextWorld();
//        loadWorld();
//    }
}

void WorldManager::render(sf::RenderTarget& target, float alpha)
{
    mWorlds[mCurrentWorld].render(target, alpha);
}

void WorldManager::handle(sf::Event& event)
{
    mWorlds[mCurrentWorld].handle(event);
}

void WorldManager::loadWorld()
{
    World world(mWorldFileNames[mCurrentWorld]);
    mWorlds.push_back(world);
}

void WorldManager::loadWorldFileNames()
{
    std::string line = "";
    std::ifstream file("assets/worlds/world_filenames.txt");

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            mWorldFileNames.push_back(line);
        }
    }

    file.close();
}

void WorldManager::resetView(sf::RenderTarget &target)
{
    mWorlds[mCurrentWorld].resetView(target);
}
