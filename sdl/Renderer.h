//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_RENDERER_H
#define TWODEE_RENDERER_H


#include <SDL_render.h>
#include <vector>
#include "Texture.h"
#include "Surface.h"
#include "Geometry.h"

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
    void copy(Texture &texture, Rect src, Rect dst);
    void present(){ SDL_RenderPresent(handle); }
    void draw(Point p) { SDL_RenderDrawPoint(handle, p.x, p.y); };
    void draw(Point p1, Point p2){ SDL_RenderDrawLine(handle, p1.x, p1.y, p2.x, p2.y); }
    void draw(Rect r){ SDL_Rect rect {r.lt.x, r.lt.y, r.size.w, r.size.h}; SDL_RenderDrawRect(handle, &rect); }
    void draw(std::vector<Point> &polygon);
    void draw(Point p, std::string text, Font &font);
};


#endif //TWODEE_RENDERER_H
