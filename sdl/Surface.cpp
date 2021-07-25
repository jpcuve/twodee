//
// Created by jpc on 30/06/21.
//

#include <stdexcept>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include "Surface.h"
#include "Font.h"

void Surface::clear(uint8_t r, uint8_t g, uint8_t b) {
    SDL_FillRect(handle, nullptr, SDL_MapRGB(handle->format, r, g, b));
}

void Surface::blit(Surface &target) {
    SDL_BlitSurface(handle, nullptr, target.handle, nullptr);
}

Surface &Surface::operator=(Surface &&that) {
    handle = that.handle;
    that.handle = nullptr;
    return *this;
}

Surface Surface::convert(SDL_PixelFormat *format) {
    return Surface {SDL_ConvertSurface(handle, format, 0)};
}

Surface Surface::fromFile(std::string path) {
    SDL_Surface *h = IMG_Load(path.c_str());
    if (h == nullptr){
        std::cerr << SDL_GetError() << std::endl;
        throw std::runtime_error("Cannot load bitmap");
    }
    return Surface(h);
}

Surface Surface::fromText(std::string text, Font &font) {
    SDL_Color color {0, 0, 0};
    SDL_Surface *h = TTF_RenderText_Solid(font.getHandle(), text.c_str(), color);
    if (h == nullptr){
        std::cerr << SDL_GetError() << std::endl;
        throw std::runtime_error("Cannot render text");
    }
    return Surface(h);
}
