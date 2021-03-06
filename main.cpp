#include <iostream>
#include "TutorialApp.h"
#include <glm/glm.hpp>
#include "Asteroids.h"

int main() {
    std::cout << "Hello, World! " << std::endl;
    glm::vec4 pos = glm::vec4(glm::vec3(0.0), 1.0);
    std::cout << pos.w << std::endl;
    asteroids::AsteroidsApp app;
    return app.run();
}
