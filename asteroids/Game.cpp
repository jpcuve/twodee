//
// Created by jpc on 25/07/21.
//

#include "Game.h"
#include "Ship.h"
#include "Bullet.h"

asteroids::Game::Game() {
    Ship ship {*this};
    items.push_back(&ship);
    Bullet bullet {*this, ship};
    items.push_back(&bullet);
    // This I may not do
    // I have to create the objects in memory as part of the game
    // then a items vector with pointers to all of them
    // that is the correct way
}
