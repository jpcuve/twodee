//
// Created by jpc on 30/06/21.
//

#ifndef TWODEE_TUTORIALAPP_H
#define TWODEE_TUTORIALAPP_H


#include "sdl/App.h"
#include "sdl/Window.h"
#include "Boulderdash.h"

class TutorialApp: public App {
private:
    Window w;
    Renderer renderer;
    Texture texture;
    Font font;
    Boulderdash game;
public:
    void init() override;
    void loop(uint32_t frame) override;
};


#endif //TWODEE_TUTORIALAPP_H
