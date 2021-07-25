//
// Created by jpc on 25/07/21.
//

#ifndef TWODEE_ASSET_H
#define TWODEE_ASSET_H


#include <vector>
#include <glm/vec2.hpp>

namespace asteroids {
    class Asset {
    public:
        static std::vector<glm::vec2> ASTEROID_SMALL;
        static std::vector<glm::vec2> ASTEROID_MEDIUM;
        static std::vector<glm::vec2> ASTEROID_BIG;
        static std::vector<glm::vec2> SHIP;
        static std::vector<glm::vec2> BULLET;
    };
}


#endif //TWODEE_ASSET_H
