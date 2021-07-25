//
// Created by jpc on 25/07/21.
//

#include "Bullet.h"
#include "Asset.h"
#include <cmath>

asteroids::Bullet::Bullet(Game& game, Ship& ship): Item {game, Asset::BULLET} {
    setPosition(ship.getPosition());
    glm::vec2 bulletSpeed {cos(ship.getRotation()) * Game::BULLET_SPEED, sin(ship.getRotation()) * Game::BULLET_SPEED};
    setSpeed(ship.getSpeed() + bulletSpeed);
}
