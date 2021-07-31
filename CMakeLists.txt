cmake_minimum_required(VERSION 3.19)
project(twodee)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(GLM REQUIRED)

include_directories($ENV{CMAKE_PREFIX_PATH}/SDL2-2.0.14/i686-w64-mingw32/include)
add_subdirectory($ENV{CMAKE_PREFIX_PATH}/SDL2-2.0.14/i686-w64-mingw32 sdl2)

include_directories(${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

add_executable(twodee main.cpp sdl/Window.cpp sdl/Window.h sdl/Surface.cpp sdl/Surface.h sdl/App.cpp sdl/App.h TutorialApp.cpp TutorialApp.h sdl/Renderer.cpp sdl/Renderer.h sdl/Texture.cpp sdl/Texture.h Boulderdash.cpp Boulderdash.h sdl/Font.cpp sdl/Font.h Asteroids.cpp Asteroids.h)
target_link_libraries(twodee ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${GLM_LIBRARIES})