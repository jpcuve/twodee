//
// Created by jpc on 1/07/21.
//

#include <iostream>
#include "Font.h"

Font &Font::operator=(Font &&that) {
    handle = that.handle;
    pointSize = that.pointSize;
    that.handle = nullptr;
    return *this;
}

Font Font::fromFile(std::string path, int ptsize) {
    TTF_Font *f = TTF_OpenFont(path.c_str(), ptsize);
    if (f == nullptr){
        std::cerr << TTF_GetError() << std::endl;
        throw std::runtime_error("Cannot open font");
    }
    return Font {f, ptsize};
}

glm::ivec2 Font::sizeText(std::string text) {
    glm::ivec2 d;
    if (TTF_SizeText(handle, text.c_str(), &d.x, &d.y) != 0){
        throw std::runtime_error("Cannot size text");
    }
    return d;
}
