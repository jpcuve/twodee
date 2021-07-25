//
// Created by jpc on 25/07/21.
//

#include "Item.h"
#include <iostream>
#include <cmath>

asteroids::Item::Item(Game& game, const std::vector<glm::vec2>& outline): game {game}, outline {outline} {
    for (glm::vec2 p: outline){
        double r = sqrt(p.x * p.x + p.y * p.y);
        if (r > radius) radius = r;
    }
#ifndef NDEBUG
    std::cout << "Radius: " << radius << std::endl;
#endif
}
