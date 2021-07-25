//
// Created by jpc on 30/06/21.
//

#ifndef TWODEE_APP_H
#define TWODEE_APP_H

#include <SDL_keyboard.h>

class App {
public:
    App();
    ~App();
    virtual void init() = 0;
    virtual void loop(uint32_t frame) = 0;
    int run();
};


#endif //TWODEE_APP_H
