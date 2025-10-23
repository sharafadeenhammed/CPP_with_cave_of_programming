#include <iostream>
#include <iomanip>

int main()
{
  unsigned char alpha = 0xff;
  unsigned char red = 0x67;
  unsigned char green = 0x90;
  unsigned char blue = 0x77;
  unsigned int color = 0x0;
  color = red;
  color <<= 8;
  color += green;
  color <<= 8;
  color += blue;
  color <<= 8;
  color += alpha;

  std::cout << std::setw(8) << std::hex << color << std::endl;
}
