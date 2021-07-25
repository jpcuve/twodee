//
// Created by jpc on 30/06/21.
//

#ifndef TWODEE_WINDOW_H
#define TWODEE_WINDOW_H

#include <SDL_video.h>
#include <memory>
#include "Surface.h"
#include "Renderer.h"


class Window {
private:
    SDL_Window *handle {nullptr};
public:
    Window();
    Window(Window &that) = delete;
    Window operator=(Window &that) = delete;
    ~Window(){ if (handle != nullptr) SDL_DestroyWindow(handle); }
    Surface getSurface(){ return Surface {SDL_GetWindowSurface(handle)}; }
    void updateSurface(){ SDL_UpdateWindowSurface(handle); }
    Renderer getRenderer(uint32_t flags) { return Renderer {SDL_CreateRenderer(handle, -1, flags)}; }
};


#endif //TWODEE_WINDOW_H
