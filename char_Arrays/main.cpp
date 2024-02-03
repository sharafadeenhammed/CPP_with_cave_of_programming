#include <iostream>

using namespace std;

int main(int args, char **argv)
{
  // char text[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  char text[] = "hello";
  for (int i = 0; i < sizeof(text); i++)
  {
    cout << i << " : " << text[i] << endl;
  }
  cout << endl;

  int k = 0;
  while (true)
  {
    if (text[k] == 0)
      break;
    cout << text[k];
    k++;
  }
  return 0;
}