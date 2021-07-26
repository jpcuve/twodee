//
// Created by jpc on 26/07/21.
//

#ifndef TWODEE_ASTEROIDS_H
#define TWODEE_ASTEROIDS_H

#include <vector>
#include <cmath>
#include <glm/vec2.hpp>
#include <iostream>

namespace aster {
    static const std::vector<glm::vec2> ASTEROID_SMALL = {
            glm::vec2{5, 5},
            glm::vec2{5, -5},
            glm::vec2{-5, -5},
            glm::vec2{-5, 5}
    };

    static const std::vector<glm::vec2> BULLET = {
            glm::vec2{-2, 0},
            glm::vec2{0, 2},
            glm::vec2{2, 0},
            glm::vec2{0, -2}
    };

    static const std::vector<glm::vec2> SHIP = {
            glm::vec2{0, 0},
            glm::vec2{-sqrt(2) * 5, sqrt(2) * 5},
            glm::vec2{10, 0},
            glm::vec2{-sqrt(2) * 5, -sqrt(2) * 5}
    };

    static const double BULLET_SPEED = 5.0;

    class Game;

    class Item {
        const Game &game;
        const std::vector<glm::vec2>& outline;
        double radius_ {0};  // TODO
        double rotation_ {0};
        double vLimit{0};
        int lifeTime{-1};
        glm::vec2 position_{0, 0};
        glm::vec2 speed_{0, 0};
        glm::vec2 acceleration_{0, 0};
    public:
        Item(Game& g, const std::vector<glm::vec2>& o);

        inline void position(const glm::vec2 p) { position_ = p; }

        inline glm::vec2 position() { return position_; }

        inline void speed(glm::vec2 s) { speed_ = s; }

        inline glm::vec2 speed() { return speed_; }

        inline void acceleration(glm::vec2 a) { acceleration_ = a; }

        inline glm::vec2 acceleration() { return acceleration_; }

        inline void rotation(double r) { rotation_ = r; }

        inline double rotation() const { return rotation_; }

        inline double radius(){ return radius_; }

        void random(float speed) {}

        void setSpeedLimit(float f) { vLimit = f; }

        virtual void info() = 0;
    };

    class Ship : public Item {
        int shootDelay{10};
    public:
        Ship(Game &g) : Item{g, SHIP} {

        }

        void info() override {
            std::cout << "Ship radius: " << radius() << std::endl;
        }

    };

    class Bullet : public Item {
    public:
        Bullet(Game& g, Ship& ship);

        void info() override {
            std::cout << "Bullet radius: " << radius() << std::endl;
        }

    };

    class Game {
        std::vector<Ship> ships;
        std::vector<Bullet> bullets;
        std::vector<Item *> items_;
        double bulletSpeed_ {5};
    public:
        Game();
        inline std::vector<Item*> items() { return items_; }
        inline Ship &ship() { return ships[0]; }
        inline double bulletSpeed(){ return bulletSpeed_; }
    };
}

#endif //TWODEE_ASTEROIDS_H
