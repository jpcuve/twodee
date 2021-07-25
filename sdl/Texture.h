//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_TEXTURE_H
#define TWODEE_TEXTURE_H


#include <SDL_render.h>

class Texture {
private:
    SDL_Texture *handle {nullptr};
public:
    Texture(SDL_Texture *h): handle(h){}
    Texture(){}
    Texture(Texture &that) = delete;
    ~Texture(){ if (handle != nullptr) SDL_DestroyTexture(handle); }
    Texture &operator=(Texture &that) = delete;
    Texture &operator=(Texture &&that);
    SDL_Texture *getHandle(){ return handle; }
};


#endif //TWODEE_TEXTURE_H
