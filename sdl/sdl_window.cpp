#include <iostream>
#include "../library/SDL2/include/SDL2/SDL.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
  bool quit = false;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    SDL_Quit();
    return 0;
  }
  SDL_Window *window = SDL_CreateWindow("particle fire emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  // check if window pointer not null
  if (window == NULL)
  {
    SDL_Quit();
    return 0;
  }
  SDL_Event event;
  while (quit == false)
  {

    // check foe sdl pool events
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        quit = true;
    }
  }
  // TODO: run game application loop and event loop

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

/**
 * @brief
 * error message
 *  g++ ./sdl_window.cpp -I../library/SDL2/include -L../library/SDL2/lib -lmingw32 -lSDL2main -lSDL2
c:/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: ../library/SDL2/lib/libSDL2main.a(SDL_windows_main.o): in function `main_getcmdline':
/Users/valve/release/SDL2/SDL2-2.30.0-source/foo-x86/../src/main/windows/SDL_windows_main.c:80: undefined reference to `SDL_main'
 *
 */