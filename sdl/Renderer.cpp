//
// Created by jpc on 1/07/21.
//

#include "Renderer.h"

Renderer &Renderer::operator=(Renderer &&that) {
    handle = that.handle;
    that.handle = nullptr;
    return *this;
}

void Renderer::copy(Texture &texture, glm::ivec4 src, glm::ivec4 dst) {
    SDL_Rect s {src.x, src.y, src.z, src.w};
    SDL_Rect d {dst.x, dst.y, dst.z, dst.w};
    SDL_RenderCopy(handle, texture.getHandle(), &s, &d);
}

void Renderer::draw(glm::ivec2 p, std::string text, Font &font) {
    Surface s = Surface::fromText(text, font);
    Texture t = createTextureFromSurface(s);
    glm::ivec2 d = font.sizeText(text);
    copy(t, {0, 0, d.x, d.y}, {p.x, p.y, d.x, d.y});
}

void Renderer::draw(std::vector<glm::ivec2> &polygon) {
    size_t s {polygon.size()};
    for (size_t i = 0; i < s; i++){
        SDL_RenderDrawLine(handle, polygon[i].x, polygon[i].y, polygon[(i + 1) % s].x, polygon[(i + 1) % s].y);
    }
}
