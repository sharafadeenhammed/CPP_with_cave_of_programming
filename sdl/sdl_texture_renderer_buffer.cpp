#include <iostream>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "../library/SDL2/include/SDL2/SDL.h"
#include "./screen.h"

// #define SCREEN_WIDTH 800
// #define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
  std::srand(time(0));
  sdl_screen::Screen screen;
  sdl_screen::Swarm swarm;
  const sdl_screen::Particle *const particleSwarm = swarm.getParticles();
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
    const int red = (1 + sin(elapsedTimefromAppStart * 0.0001)) * 127.5;
    const int green = (1 + sin(elapsedTimefromAppStart * 0.0002)) * 127.5;
    const int blue = (1 + sin(elapsedTimefromAppStart * 0.0003)) * 127.5;

    for (int i = 0; i < swarm.m_NUM_OF_PARTICLE; i++)
    {
      sdl_screen::Particle particle = particleSwarm[i];
      const int x = particle.m_x * screen.SCREEN_WIDTH;
      const int y = particle.m_y * screen.SCREEN_HEIGHT;
      screen.setPixel(x, y, red, green, blue, 0xff);
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