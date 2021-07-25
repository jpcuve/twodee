//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_FONT_H
#define TWODEE_FONT_H


#include <string>
#include <SDL_ttf.h>
#include "Geometry.h"

class Font {
private:
    TTF_Font *handle {nullptr};
    int pointSize {0};
public:
    Font(TTF_Font *h, int ptsize): handle(h), pointSize(ptsize){}
    Font(){}
    Font(Font &that) = delete;
    ~Font(){ if (handle != nullptr) TTF_CloseFont(handle); }
    Font &operator=(Font &that) = delete;
    Font &operator=(Font &&that);
    TTF_Font *getHandle(){ return handle; }
    int getPointSize(){ return pointSize; }
    static Font fromFile(std::string path, int ptsize);
    Dimension sizeText(std::string text);
};


#endif //TWODEE_FONT_H
