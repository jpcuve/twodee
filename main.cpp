#include <iostream>
#include "TutorialApp.h"
#include "asteroids/Asset.h"
#include <glm/glm.hpp>

int main() {
    std::cout << "Hello, World! " << std::endl;
    glm::vec4 pos = glm::vec4(glm::vec3(0.0), 1.0);
    std::cout << pos.w << std::endl;
    for (glm::vec2& p: asteroids::Asset::SHIP) {
        std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
    }
    TutorialApp app;
    return app.run();
}
