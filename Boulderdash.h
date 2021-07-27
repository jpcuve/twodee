//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_BOULDERDASH_H
#define TWODEE_BOULDERDASH_H


#include <vector>
#include <cstdint>
#include <glm/glm.hpp>


class Boulderdash {
private:
    const std::vector<glm::ivec2> MAGMA = {{0, 256}, {32, 256}, {64, 256}, {96, 256}, {128, 256}, {160, 256}, {192, 256}, {224, 256}};
    const std::vector<glm::ivec2> ROCKFORD = {{0, 32}, {0, 32}, {0, 32}, {0, 32}, {0, 32}, {0, 32}, {0, 32}, {0, 32}};
    const std::vector<glm::ivec2> ROCKFORD_EYES = {{0, 32}, {32, 32}, {64, 32}, {96, 32}, {128, 32}, {160, 32}, {192, 32}, {224, 32}};
    const std::vector<glm::ivec2> ROCKFORD_WAIT1 = {{0, 64}, {32, 64}, {64, 64}, {96, 64}, {128, 64}, {160, 64}, {192, 64}, {224, 64}};
    const std::vector<glm::ivec2> ROCKFORD_WAIT2 = {{0, 96}, {32, 96}, {64, 96}, {96, 96}, {128, 96}, {160, 96}, {192, 96}, {224, 96}};
    const std::vector<glm::ivec2> ROCKFORD_LEFT = {{0, 128}, {32, 128}, {64, 128}, {96, 128}, {128, 128}, {160, 128}, {192, 128}, {224, 128}};
    const std::vector<glm::ivec2> ROCKFORD_RIGHT = {{0, 160}, {32, 160}, {64, 160}, {96, 160}, {128, 160}, {160, 160}, {192, 160}, {224, 160}};
    const std::vector<glm::ivec2> DIAMOND = {{0, 320}, {32, 320}, {64, 320}, {96, 320}, {128, 320}, {160, 320}, {192, 320}, {224, 320}};

    const std::vector<glm::ivec2> *ROCKFORD_WAIT_STATES[4] = {
            &ROCKFORD,
            &ROCKFORD_EYES,
            &ROCKFORD_WAIT1,
            &ROCKFORD_WAIT2
    };
    const std::vector<glm::ivec2> *wait {&ROCKFORD_EYES};
public:
    Boulderdash(){}
    void update(uint32_t tick);
    glm::ivec2 getRockfordWait(uint32_t tick){ return (*wait)[tick % ROCKFORD.size()]; }
    glm::ivec2 getRockfordLeft(uint32_t tick){ return ROCKFORD_LEFT[tick % ROCKFORD_LEFT.size()]; }
    glm::ivec2 getRockfordRight(uint32_t tick){ return ROCKFORD_RIGHT[tick % ROCKFORD_RIGHT.size()]; }
    glm::ivec2 getMagma(uint32_t tick){ return MAGMA[tick % MAGMA.size()]; }
    glm::ivec2 getDiamond(uint32_t tick){ return DIAMOND[tick % DIAMOND.size()]; }
};


#endif //TWODEE_BOULDERDASH_H
