//
// Created by jpc on 30/06/21.
//

#include <SDL_render.h>
#include "Window.h"

Window::Window() {
    handle = SDL_CreateWindow("title", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
    if (handle == nullptr){
        throw std::runtime_error("Cannot create window");
    }
}

