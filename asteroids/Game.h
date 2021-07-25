//
// Created by jpc on 25/07/21.
//

#ifndef TWODEE_GAME_H
#define TWODEE_GAME_H

#include <vector>


namespace asteroids{
    class Item;

    class Game {
    private:
        std::vector<Item*> items;
    public:
        inline static double BULLET_SPEED = 5.0;
        Game();
    };
}


#endif //TWODEE_GAME_H
