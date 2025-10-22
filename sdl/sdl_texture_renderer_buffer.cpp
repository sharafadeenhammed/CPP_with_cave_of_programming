#include <iostream>
#include <cstring>
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
  std::cout << "window created ..." << std::endl;
  SDL_Event event;
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) // check if renderer created
  {
    std::cout << "failed to create sdl renderer" << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }
  std::cout << "renderer created ..." << std::endl;
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
  if (texture == NULL) // check if texture created
  {
    std::cout << "failed to create sdl texture" << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }
  std::cout << "texture created ..." << std::endl;

  Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // pixel data buffer
  SDL_memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
  // memset(buffer, 0xfff, SCREEN_WIDTH * SCREEN_HEIGHT);
  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  // game loop...
  while (quit == false)
  {
    // TODO: run game application loop

    // check for sdl pool events
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        quit = true;
    }
  }

  // clear and free application resourses.
  delete[] buffer;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "application closed ..." << std::endl;
  return 0;
}

/**
 * @brief
 * compilation command
 *  g++ ./sdl_texture_renderer_buffer.cpp -I../library/SDL2/include -L../library/SDL2/lib -lmingw32 -lSDL2main -lSDL2
 *
 */