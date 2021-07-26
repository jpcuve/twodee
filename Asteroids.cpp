//
// Created by jpc on 26/07/21.
//

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
        const std::vector<glm::vec2> outline;
        double radius_ {0};  // TODO
        double rotation_ {0};
        double vLimit{0};
        int lifeTime{-1};
        glm::vec2 position_{0, 0};
        glm::vec2 speed_{0, 0};
        glm::vec2 acceleration_{0, 0};
    public:
        Item(Game &g, const std::vector<glm::vec2> &o) : game{g}, outline{o} {
            for (auto &p: outline) {
                double r = sqrt((double) (p.x * p.x + p.y * p.y));
                if (r > radius_) radius_ = r;
            }
        }

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
        Bullet(Game &g, Ship &ship) : Item{g, BULLET} {
            position(ship.position());
            glm::vec2 bulletSpeed{cos(ship.rotation()) * BULLET_SPEED, sin(ship.rotation()) * BULLET_SPEED};
            speed(ship.speed() + bulletSpeed);
        }

        void info() override {
            std::cout << "Bullet radius: " << radius() << std::endl;
        }

    };

    class Game {
        std::vector<Ship> ships;
        std::vector<Bullet> bullets;
        std::vector<Item *> items_;
    public:
        Game() {
            ships.emplace_back(*this);
            for (int i = 0; i < 3; i++) {
                bullets.emplace_back(*this, ships[0]);
            }
            for (auto &ship: ships) items_.push_back(&ship);
            for (auto &bullet: bullets) items_.push_back(&bullet);
        }

        inline std::vector<Item*> items() { return items_; }
        inline Ship &ship() { return ships[0]; }
    };
}