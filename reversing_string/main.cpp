#include <iostream>

using namespace std;
int main(int args, char **Argv)
{
  char text[] = "abcdef";
  char *pTextStart = text;
  char *pTextEnd = text + sizeof(text) - 2;
  cout << "initial value of text " << text << endl
       << endl;

  while (pTextStart < pTextEnd)
  {
    cout << ".";
    // copy current value of pTextStart...
    char pTextStartCopy = *pTextStart;

    // copy value pTextEnd to pTextStart
    *pTextStart = *pTextEnd;
    *pTextEnd = pTextStartCopy;

    // move the pTextEnd toward the beginning of the string by 1;
    pTextEnd--;
    // move the pTextStart towards the end of the string by 1
    pTextStart++;
  }

  cout << "final value of text : " << text << endl;
  return 0;
}