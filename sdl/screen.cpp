#include "./screen.h"
// namespace sdl_screen
// {
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
  SDL_memset(m_buffer, 0xff, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

  if (m_window == NULL || m_renderer == NULL || m_texture == NULL || m_buffer == NULL)
    return false;

  SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(m_renderer);
  SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
  SDL_RenderPresent(m_renderer);

  return true;
}
bool Screen::processEvents()
{
  return false;
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

// }