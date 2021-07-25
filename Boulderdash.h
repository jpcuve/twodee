//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_BOULDERDASH_H
#define TWODEE_BOULDERDASH_H


#include <vector>
#include <cstdint>
#include "sdl/Geometry.h"



class Boulderdash {
private:
    const Dimension TILE_SIZE {32, 32};
    const std::vector<Rect> MAGMA = {
            Rect{Point{0, 256}, TILE_SIZE},
            Rect{Point{32, 256}, TILE_SIZE},
            Rect{Point{64, 256}, TILE_SIZE},
            Rect{Point{96, 256}, TILE_SIZE},
            Rect{Point{128, 256}, TILE_SIZE},
            Rect{Point{160, 256}, TILE_SIZE},
            Rect{Point{192, 256}, TILE_SIZE},
            Rect{Point{224, 256}, TILE_SIZE},
    };
    const std::vector<Rect> ROCKFORD = {
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{0, 32}, TILE_SIZE},
    };
    const std::vector<Rect> ROCKFORD_EYES = {
            Rect{Point{0, 32}, TILE_SIZE},
            Rect{Point{32, 32}, TILE_SIZE},
            Rect{Point{64, 32}, TILE_SIZE},
            Rect{Point{96, 32}, TILE_SIZE},
            Rect{Point{128, 32}, TILE_SIZE},
            Rect{Point{160, 32}, TILE_SIZE},
            Rect{Point{192, 32}, TILE_SIZE},
            Rect{Point{224, 32}, TILE_SIZE},
    };
    const std::vector<Rect> ROCKFORD_WAIT1 = {
            Rect{Point{0, 64}, TILE_SIZE},
            Rect{Point{32, 64}, TILE_SIZE},
            Rect{Point{64, 64}, TILE_SIZE},
            Rect{Point{96, 64}, TILE_SIZE},
            Rect{Point{128, 64}, TILE_SIZE},
            Rect{Point{160, 64}, TILE_SIZE},
            Rect{Point{192, 64}, TILE_SIZE},
            Rect{Point{224, 64}, TILE_SIZE},
    };
    const std::vector<Rect> ROCKFORD_WAIT2 = {
            Rect{Point{0, 96}, TILE_SIZE},
            Rect{Point{32, 96}, TILE_SIZE},
            Rect{Point{64, 96}, TILE_SIZE},
            Rect{Point{96, 96}, TILE_SIZE},
            Rect{Point{128, 96}, TILE_SIZE},
            Rect{Point{160, 96}, TILE_SIZE},
            Rect{Point{192, 96}, TILE_SIZE},
            Rect{Point{224, 96}, TILE_SIZE},
    };
    const std::vector<Rect> ROCKFORD_LEFT = {
            Rect{Point{0, 128}, TILE_SIZE},
            Rect{Point{32, 128}, TILE_SIZE},
            Rect{Point{64, 128}, TILE_SIZE},
            Rect{Point{96, 128}, TILE_SIZE},
            Rect{Point{128, 128}, TILE_SIZE},
            Rect{Point{160, 128}, TILE_SIZE},
            Rect{Point{192, 128}, TILE_SIZE},
            Rect{Point{224, 128}, TILE_SIZE},
    };
    const std::vector<Rect> ROCKFORD_RIGHT = {
            Rect{Point{0, 160}, TILE_SIZE},
            Rect{Point{32, 160}, TILE_SIZE},
            Rect{Point{64, 160}, TILE_SIZE},
            Rect{Point{96, 160}, TILE_SIZE},
            Rect{Point{128, 160}, TILE_SIZE},
            Rect{Point{160, 160}, TILE_SIZE},
            Rect{Point{192, 160}, TILE_SIZE},
            Rect{Point{224, 160}, TILE_SIZE},
    };
    const std::vector<Rect> DIAMOND = {
            Rect{Point{0, 320}, TILE_SIZE},
            Rect{Point{32, 320}, TILE_SIZE},
            Rect{Point{64, 320}, TILE_SIZE},
            Rect{Point{96, 320}, TILE_SIZE},
            Rect{Point{128, 320}, TILE_SIZE},
            Rect{Point{160, 320}, TILE_SIZE},
            Rect{Point{192, 320}, TILE_SIZE},
            Rect{Point{224, 320}, TILE_SIZE},
    };

    const std::vector<Rect> *ROCKFORD_WAIT_STATES[4] = {
            &ROCKFORD,
            &ROCKFORD_EYES,
            &ROCKFORD_WAIT1,
            &ROCKFORD_WAIT2
    };
    const std::vector<Rect> *wait {&ROCKFORD_EYES};
public:
    Boulderdash(){}
    void update(uint32_t tick);
    Dimension getTileSize(){ return TILE_SIZE; }
    Rect getRockfordWait(uint32_t tick){ return (*wait)[tick % ROCKFORD.size()]; }
    Rect getRockfordLeft(uint32_t tick){ return ROCKFORD_LEFT[tick % ROCKFORD_LEFT.size()]; }
    Rect getRockfordRight(uint32_t tick){ return ROCKFORD_RIGHT[tick % ROCKFORD_RIGHT.size()]; }
    Rect getMagma(uint32_t tick){ return MAGMA[tick % MAGMA.size()]; }
    Rect getDiamond(uint32_t tick){ return DIAMOND[tick % DIAMOND.size()]; }
};


#endif //TWODEE_BOULDERDASH_H
