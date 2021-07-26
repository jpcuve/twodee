//
// Created by jpc on 26/07/21.
//

#include "Asteroids.h"

aster::Item::Item(aster::Game &g, const std::vector<glm::vec2> &o) : game{g}, outline{o} {
    for (auto &p: outline) {
        double r = sqrt((double) (p.x * p.x + p.y * p.y));
        if (r > radius_) radius_ = r;
    }
}

aster::Bullet::Bullet(Game &g, Ship &ship) : Item{g, BULLET} {
    position(ship.position());
    glm::vec2 bulletSpeed{cos(ship.rotation()) * g.bulletSpeed(), sin(ship.rotation()) * g.bulletSpeed()};
    speed(ship.speed() + bulletSpeed);
}

aster::Game::Game() {
    ships.emplace_back(*this);
    for (int i = 0; i < 3; i++) {
        bullets.emplace_back(*this, ships[0]);
    }
    for (auto &ship: ships) items_.push_back(&ship);
    for (auto &bullet: bullets) items_.push_back(&bullet);
}

