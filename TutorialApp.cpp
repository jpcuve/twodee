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
    renderer.draw(Point {10, 10});
    renderer.draw(Point{10, 10}, Point{200, 100});
    renderer.draw(Rect{Point{5, 5}, Dimension{200, 300}});
    std::vector<Point> p = {
            Point{-20, 330},
            Point{300, 350},
            Point{120, 300}
    };
    renderer.draw(p);
    Rect src = game.getMagma(tick);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            renderer.copy(texture, src, Rect{Point{50 + i * 32, 50 + j * 32}, game.getTileSize()});
        }
    }
    src = game.getDiamond(tick);
    renderer.copy(texture, src, Rect{Point{220, 64}, game.getTileSize()});
    renderer.draw(Point(10, 250), "Hello world!", font);
    std::stringstream ss;
    ss << "Frame: " << frame;
    renderer.draw(Point(10, 270), ss.str(), font);
    Rect player = game.getRockfordWait(tick);
    const uint8_t *keyStates = SDL_GetKeyboardState(nullptr);
    if (keyStates[SDL_SCANCODE_LEFT]){
        player = game.getRockfordLeft(tick);
    } else if (keyStates[SDL_SCANCODE_RIGHT]){
        player = game.getRockfordRight(tick);
    }
    renderer.copy(texture, player, Rect{Point{220, 32}, game.getTileSize()});
    renderer.present();
}

