#include <iostream>
#include <cstring>
#include <math.h>
#include "../library/SDL2/include/SDL2/SDL.h"
#include "./screen.h"

// #define SCREEN_WIDTH 800
// #define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
  sdl_screen::Screen screen;

  if (screen.init() == false)
  {
    std::cout << "error initializing application" << std::endl;
    return 1;
  }

  // game loop...
  while (1)
  {
    // TODO: run game application loop
    const int elapsedTimefromAppStart = SDL_GetTicks();

    const int color = sin(elapsedTimefromAppStart * 0.001) * 127.5;
    for (int y = 0; y < screen.SCREEN_HEIGHT; y++)
    {
      for (int x = 0; x < screen.SCREEN_WIDTH; x++)
        screen.setPixel(x, y, 0x00, color, 0x00, 0x00);
    }
    screen.updateScreen();
    if (screen.processEvents() == false)
      break;
  }

  // clear and free application resourses.
  screen.close();
  return 0;
}

/**
 * @brief
 * compilation command
 *  g++ ./sdl_texture_renderer_buffer.cpp ./screen.cpp -I../library/SDL2/include -L../library/SDL2/lib -lmingw32 -lSDL2main -lSDL2
 *
 */