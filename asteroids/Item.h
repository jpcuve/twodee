//
// Created by jpc on 25/07/21.
//

#ifndef TWODEE_ITEM_H
#define TWODEE_ITEM_H


#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include "Game.h"

namespace asteroids {
    class Item {
    private:
        const Game& game;
        const std::vector<glm::vec2>& outline;
        double radius {0};  // TODO
        double rot {0};
        double vLimit {0};
        int lifeTime {-1};
        glm::vec2 p {0, 0};
        glm::vec2 v {0, 0};
        glm::vec2 a {0, 0};
    public:
        Item(Game& game, const std::vector<glm::vec2>& outline);
        void setPosition(glm::vec2 position){ p = position; }
        glm::vec2 getPosition(){ return p; }
        void setSpeed(glm::vec2 speed){ v = speed; }
        glm::vec2 getSpeed(){ return v; }
        void setAcceleration(glm::vec2 acceleration){ a = acceleration; }
        glm::vec2 getAcceleration(){ return a; }
        double getRotation(){ return rot; }
        void setRotation(double rotation){ rot = rotation; }
        void random(float speed);
        void setSpeedLimit(float f) { vLimit = f; }
    };
}

#endif //TWODEE_ITEM_H
