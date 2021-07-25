//
// Created by jpc on 30/06/21.
//

#include <SDL.h>
#include <stdexcept>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include "App.h"

App::App() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << SDL_GetError() << std::endl;
        throw std::runtime_error("Cannot initialize SDL");
    }
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)){
        std::cerr << IMG_GetError() << std::endl;
        throw std::runtime_error("Cannot initialize SDL_image");
    }
    if (TTF_Init() == -1){
        std::cerr << TTF_GetError() << std::endl;
        throw std::runtime_error("Cannot initialize SDL_ttf");
    }
}

App::~App() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int App::run() {
    init();
    bool quit = false;
    SDL_Event e;
    uint32_t frame {0};
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            switch(e.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
//                    keyDown(e.key.keysym.sym);
                    break;
            }
        }
        loop(frame);
        ++frame;
    }
    return 0;
}
