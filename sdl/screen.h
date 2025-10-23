#ifndef _SCREEN_
#define _SCREEN_
#include "../library/SDL2/include/SDL2/SDL.h"

namespace sdl_screen
{
  class Screen
  {
  public: // constant public variables
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

  private: // private member vairable
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    SDL_Event m_event;
    /* data */
  public: // public methods
    Screen(/* args */);
    bool init();
    bool processEvents();
    void close();
    void setPixel(unsigned int x, unsigned int y, uint8_t red = 0x00, uint8_t green = 0x00, uint8_t blue = 0x00, uint8_t alpha = 0xFF);
    void updateScreen();
    ~Screen() {};
  };

  class Particle
  {
  public:
    double m_x;
    double m_y;

  public:
    Particle();
    ~Particle();
  };

  class Swarm
  {
  public:
    static const int m_NUM_OF_PARTICLE = 5000;

  private:
    Particle *m_particles;

  public:
    Swarm();
    ~Swarm();
    const Particle *const getParticles();
  };
}
#endif // MACRO
