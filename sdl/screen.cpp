#include "./screen.h"
#include <stdlib.h>
namespace sdl_screen
{
  // screen class implementation
  Screen::Screen() : m_window(NULL), m_buffer(NULL), m_texture(NULL), m_renderer(NULL)
  {
  }
  bool Screen::init()
  {
    m_window = SDL_CreateWindow("particle fire emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == NULL) // check if window created
    {
      SDL_Quit();
      return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == NULL) // check if renderer created
    {
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (m_texture == NULL) // check if texture created
    {
      SDL_DestroyRenderer(m_renderer);
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }
    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    return true;
  }
  bool Screen::processEvents()
  {
    // check for sdl pool events
    while (SDL_PollEvent(&m_event))
    {
      if (m_event.type == SDL_QUIT)
        return false;
    }
    return true;
  }

  void Screen::setPixel(unsigned int x, unsigned int y, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
  {
    Uint32 pixelColor = 0x00;
    pixelColor = red;
    pixelColor <<= 8;
    pixelColor += green;
    pixelColor <<= 8;
    pixelColor += blue;
    pixelColor <<= 8;
    pixelColor += alpha;
    m_buffer[(y * SCREEN_WIDTH) + x] = pixelColor;
  }

  void Screen::updateScreen()
  {
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
  }
  void Screen::clear()
  {
    SDL_memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
  }

  void Screen::close()
  {
    if (m_texture != NULL)
      SDL_DestroyTexture(m_texture);
    if (m_renderer != NULL)
      SDL_DestroyRenderer(m_renderer);
    if (m_window != NULL)
      SDL_DestroyWindow(m_window);
    delete[] m_buffer;
    SDL_Quit();
  }

  // particle class implementation
  Particle::Particle()
  {
    m_speed_x = (double)((std::rand() * 2.0 / RAND_MAX) - 1) / 100;
    m_speed_y = (double)((std::rand() * 2.0 / RAND_MAX) - 1) / 100;
    m_x = (double)(std::rand() * 1.0 / RAND_MAX);
    m_y = (double)(std::rand() * 2.0 / RAND_MAX);
  }

  Particle::~Particle()
  {
  }
  void Particle::changePosition()
  {
    // m_speed_x = (double)((std::rand() * 2.0 / RAND_MAX) - 1) / 100;
    // m_speed_y = (double)((std::rand() * 2.0 / RAND_MAX) - 1) / 100;
    // m_x = (m_x + m_speed_x) >= 1.0 ? (double)(std::rand() * 1.0 / RAND_MAX) : m_x + m_speed_x;
    // m_y = (m_y + m_speed_y) >= +1.0 ? (double)(std::rand() * 1.0 / RAND_MAX) : m_y + m_speed_y;
    m_x += m_speed_x;
    m_y += m_speed_y;
    if (m_x >= 1 || m_x <= 0)
      m_speed_x += -2 * m_speed_x;
    if (m_y >= 1 || m_y <= 0)
      m_speed_y += -2 * m_speed_y;
  }

  Swarm::Swarm()
  {
    m_particles = new Particle[m_NUM_OF_PARTICLE];
  }

  Swarm::~Swarm()
  {
    delete[] m_particles;
  }

  const Particle *const Swarm::getParticles()
  {
    return m_particles;
  }

  void Swarm::updateParticleSwarmPosition()
  {
    for (int i = 0; i < m_NUM_OF_PARTICLE; i++)
    {
      m_particles[i].changePosition();
    }
  }

}
