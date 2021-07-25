//
// Created by jpc on 25/07/21.
//

#include "Asset.h"
#include <cmath>

std::vector<glm::vec2> asteroids::Asset::ASTEROID_SMALL = {
        glm::vec2 {5, 5},
        glm::vec2 {5, -5},
        glm::vec2 {-5, -5},
        glm::vec2 {-5, 5}
};

std::vector<glm::vec2> asteroids::Asset::ASTEROID_MEDIUM = {
        glm::vec2 {10, 10},
        glm::vec2 {10, -10},
        glm::vec2 {-10, -10},
        glm::vec2 {-10, 10}
};

std::vector<glm::vec2> asteroids::Asset::ASTEROID_BIG = {
        glm::vec2 {0, 28.4},
        glm::vec2 {8, 22},
        glm::vec2 {16, 26},
        glm::vec2 {28.4, 0},
        glm::vec2 {16, -16},
        glm::vec2 {16, -26},
        glm::vec2 {-8, -28.4},
        glm::vec2 {-14, -18},
        glm::vec2 {-28.4, -10},
        glm::vec2 {-20, 16}
};

std::vector<glm::vec2> asteroids::Asset::SHIP = {
        glm::vec2 {0, 0},
        glm::vec2 {-sqrt(2) * 5, sqrt(2) * 5},
        glm::vec2 {10, 0},
        glm::vec2 {-sqrt(2) * 5, -sqrt(2) * 5}
};

std::vector<glm::vec2> asteroids::Asset::BULLET = {
        glm::vec2 {-2, 0},
        glm::vec2 {0, 2},
        glm::vec2 {2, 0},
        glm::vec2 {0, -2}
};