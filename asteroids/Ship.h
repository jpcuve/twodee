//
// Created by jpc on 25/07/21.
//

#ifndef TWODEE_SHIP_H
#define TWODEE_SHIP_H

#include "Item.h"

namespace asteroids {
    class Ship: public Item {
    private:
        int shootDelay {10};
    public:
        Ship(Game& game);

    };
}


#endif //TWODEE_SHIP_H
