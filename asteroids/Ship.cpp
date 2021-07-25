//
// Created by jpc on 25/07/21.
//

#include "Ship.h"
#include "Asset.h"

asteroids::Ship::Ship(Game& game): Item {game, Asset::SHIP} {
    setSpeedLimit(5);
}
