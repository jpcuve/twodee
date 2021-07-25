//
// Created by jpc on 1/07/21.
//

#include "Texture.h"

Texture &Texture::operator=(Texture &&that) {
    handle = that.handle;
    that.handle = nullptr;
    return *this;
}
