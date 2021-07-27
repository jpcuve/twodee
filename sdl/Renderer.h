//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_RENDERER_H
#define TWODEE_RENDERER_H


#include <SDL_render.h>
#include <vector>
#include <glm/glm.hpp>
#include "Texture.h"
#include "Surface.h"

class Renderer {
private:
    SDL_Renderer *handle {nullptr};
public:
    Renderer(SDL_Renderer *h): handle(h){}
    Renderer(){}
    Renderer(Renderer &that) = delete;
    ~Renderer(){ if (handle != nullptr) SDL_DestroyRenderer(handle); }
    Renderer &operator=(Renderer &that) = delete;
    Renderer &operator=(Renderer &&that);
    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a){ SDL_SetRenderDrawColor(handle, r, g, b, a); }
    Texture createTextureFromSurface(Surface &surface){ return Texture {SDL_CreateTextureFromSurface(handle, surface.getHandle())}; }
    void clear(){ SDL_RenderClear(handle); }
    void copy(Texture &texture, glm::ivec4 src, glm::ivec4 dst);
    void present(){ SDL_RenderPresent(handle); }
    void draw(glm::ivec2 p) { SDL_RenderDrawPoint(handle, p.x, p.y); };
    void draw(glm::ivec2 p1, glm::ivec2 p2){ SDL_RenderDrawLine(handle, p1.x, p1.y, p2.x, p2.y); }
    void draw(glm::ivec4 r){ SDL_Rect rect {r.x, r.y, r.z, r.w}; SDL_RenderDrawRect(handle, &rect); }
    void draw(std::vector<glm::ivec2> &polygon);
    void draw(glm::ivec2 p, std::string text, Font &font);
};


#endif //TWODEE_RENDERER_H
