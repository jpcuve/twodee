//
// Created by jpc on 30/06/21.
//

#ifndef TWODEE_SURFACE_H
#define TWODEE_SURFACE_H


#include <iostream>
#include <SDL_surface.h>
#include "Texture.h"
#include "Font.h"

class Surface {
private:
    SDL_Surface *handle {nullptr};
public:
    Surface(SDL_Surface *surface): handle{surface} {};
    Surface(){}
    Surface(Surface &that) = delete;
    Surface &operator=(Surface &that) = delete;
    Surface &operator=(Surface &&that);
    ~Surface(){ if (handle != nullptr) SDL_FreeSurface(handle); };
    SDL_Surface *getHandle(){ return handle; }
    void clear(uint8_t r, uint8_t g, uint8_t b);
    void blit(Surface &target);
    SDL_PixelFormat *getFormat(){ return handle->format; }
    Surface convert(SDL_PixelFormat *format);
    static Surface fromFile(std::string path);
    static Surface fromText(std::string text, Font &font);
};


#endif //TWODEE_SURFACE_H
