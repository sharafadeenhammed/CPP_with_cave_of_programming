#include <iostream>
#include "../library/SDL2/include/SDL2/SDL.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
  bool quit = false;
  const bool initSDL = SDL_Init(SDL_INIT_VIDEO) <= 0;
  if (!initSDL)
  {
    SDL_Quit();
    return 1;
  }
  SDL_Window *window = SDL_CreateWindow("sdl texture renderer buffer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  { // clear and quit sdl on window fail
    SDL_Quit();
    return 1;
  }

  SDL_Event event; // create events
  while (quit == false)
  {

    // check for quit event and break the application loop
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        quit = true;
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
}
