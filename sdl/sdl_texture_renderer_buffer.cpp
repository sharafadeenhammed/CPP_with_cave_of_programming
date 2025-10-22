#include <iostream>
#include <cstring>
#include "../library/SDL2/include/SDL2/SDL.h"
#include "./screen.h"
#include "./screen.cpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
  bool quit = false;
  Screen screen;

  if (screen.init() == false)
  {
    std::cout << "error initializing application" << std::endl;
    return 1;
  }

  // game loop...
  while (quit == false)
  {
    // TODO: run game application loop

    SDL_Event event;
    // check for sdl pool events
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        quit = true;
    }
  }

  // clear and free application resourses.
  screen.close();
  return 0;
}

/**
 * @brief
 * compilation command
 *  g++ ./sdl_texture_renderer_buffer.cpp -I../library/SDL2/include -L../library/SDL2/lib -lmingw32 -lSDL2main -lSDL2
 *
 */