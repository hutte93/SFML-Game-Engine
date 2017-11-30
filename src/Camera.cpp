#include "Camera.hpp"

#include "Constants.hpp"

Camera::Camera()
{
    mView = sf::View(sf::FloatRect(mCenter.x, mCenter.y, SCREEN_WIDTH, SCREEN_HEIGHT));
}

Camera::~Camera()
{
    //dtor
}

void Camera::follow(sf::Vector2f center)
{
    mOldCenter = mCenter;
    mCenter = center;

    mView.setCenter(mCenter);
}
