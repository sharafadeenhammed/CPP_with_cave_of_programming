#ifndef _SCREEN_
#define _SCREEN_
#include "../library/SDL2/include/SDL2/SDL.h"

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
  ~Screen() {};
};

#endif // MACRO
