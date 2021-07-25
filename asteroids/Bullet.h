//
// Created by jpc on 25/07/21.
//

#ifndef TWODEE_BULLET_H
#define TWODEE_BULLET_H

#include "Ship.h"

namespace asteroids {
    class Bullet: public Item {
    public:
        Bullet(Game& game, Ship& ship);

    };
}


#endif //TWODEE_BULLET_H
