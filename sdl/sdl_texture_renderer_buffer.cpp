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

  if (window == NULL) // check if window created
  {
    SDL_Quit();
    return 0;
  }
  std::cout << "window created ...";
  SDL_Event event;
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) // check if renderer created
  {
    std::cout << "failed to create sdl renderer";
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }
  std::cout << "renderer created ...";
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
  if (texture == NULL) // check if texture created
  {
    std::cout << "failed to create sdl texture";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }
  std::cout << "texture created ...";

  Uint32 *butffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // pixel data buffer

  // game loop...
  while (quit == false)
  {

    // check for sdl pool events
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        quit = true;
    }
    // TODO: run game application loop
  }

  // clear and free application resourses.
  delete[] butffer;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "application closed ...";
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