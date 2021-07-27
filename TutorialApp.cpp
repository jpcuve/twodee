//
// Created by jpc on 30/06/21.
//

#include <iostream>
#include <sstream>
#include "TutorialApp.h"
#include "Boulderdash.h"

void TutorialApp::init() {
    renderer = w.getRenderer(SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    Surface s = Surface::fromFile("/home/jpc/Development/twodee/boulderdash.png");
    texture = renderer.createTextureFromSurface(s);
    font = Font::fromFile("/home/jpc/Development/twodee/PixelEmulator-xq08.ttf", 20);
}

void TutorialApp::loop(uint32_t frame) {
    uint32_t tick {frame >> 2};
    if (frame % 4 == 0) game.update(tick);
    renderer.setDrawColor(0xFF, 0xFF, 0x80, 0xFF);
    renderer.clear();
    renderer.setDrawColor(0xFF, 0, 0, 0xFF);
    renderer.draw({10, 10});
    renderer.draw({10, 10}, {200, 100});
    renderer.draw({5, 5, 200, 300});
    std::vector<glm::ivec2> p = {{-20, 330}, {300, 350}, {120, 300}};
    renderer.draw(p);
    auto src = glm::ivec4{game.getMagma(tick), 32, 32};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            renderer.copy(texture, src, {50 + i * 32, 50 + j * 32, 32, 32});
        }
    }
    src = glm::ivec4{game.getDiamond(tick), 32, 32}; ;
    renderer.copy(texture, src, glm::vec4{220, 64, 32, 32});
    renderer.draw({10, 250}, "Hello world!", font);
    std::stringstream ss;
    ss << "Frame: " << frame;
    renderer.draw({10, 270}, ss.str(), font);
    auto player = game.getRockfordWait(tick);
    const uint8_t *keyStates = SDL_GetKeyboardState(nullptr);
    if (keyStates[SDL_SCANCODE_LEFT]){
        player = game.getRockfordLeft(tick);
    } else if (keyStates[SDL_SCANCODE_RIGHT]){
        player = game.getRockfordRight(tick);
    }
    renderer.copy(texture, glm::vec4{player, 32, 32}, {220, 32, 32, 32});
    renderer.present();
}

