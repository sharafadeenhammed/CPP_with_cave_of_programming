

#include <iostream>
#include "../library/SDL2/include/SDL2/SDL.h"
using namespace std;

int main(int argc, char **argv)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    cout << "video init failed...";
    return 1;
  }
  else
    cout << "video init okay...";
  SDL_Quit();
  cout << "hello world";
  return 0;
}