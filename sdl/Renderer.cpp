//
// Created by jpc on 1/07/21.
//

#include "Renderer.h"

Renderer &Renderer::operator=(Renderer &&that) {
    handle = that.handle;
    that.handle = nullptr;
    return *this;
}

void Renderer::copy(Texture &texture, Rect src, Rect dst) {
    SDL_Rect s {src.lt.x, src.lt.y, src.size.w, src.size.h};
    SDL_Rect d {dst.lt.x, dst.lt.y, dst.size.w, dst.size.h};
    SDL_RenderCopy(handle, texture.getHandle(), &s, &d);
}

void Renderer::draw(Point p, std::string text, Font &font) {
    Surface s = Surface::fromText(text, font);
    Texture t = createTextureFromSurface(s);
    Dimension d = font.sizeText(text);
    copy(t, Rect{Point(), d}, Rect{p, d});
}

void Renderer::draw(std::vector<Point> &polygon) {
    size_t s {polygon.size()};
    for (size_t i = 0; i < s; i++){
        SDL_RenderDrawLine(handle, polygon[i].x, polygon[i].y, polygon[(i + 1) % s].x, polygon[(i + 1) % s].y);
    }
}
