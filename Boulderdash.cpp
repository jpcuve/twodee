//
// Created by jpc on 1/07/21.
//

#include "Boulderdash.h"
#include <cstdlib>

void Boulderdash::update(uint32_t tick) {
    if (tick % 8 == 0){
        wait = ROCKFORD_WAIT_STATES[rand() % 4];
    }

}
