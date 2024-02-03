#include <iostream>
using namespace std;

int main(int args, char **argv)
{

  string texts[] = {"one", "two", "three"};

  string *pTexts = texts;

  for (int i = 0; i < sizeof(texts) / sizeof(string); i++)
  {
    cout << texts[i] << " ";
  }

  cout << endl;
  for (int i = 0; i < sizeof(texts) / sizeof(string); i++, pTexts++)
  {
    cout << *pTexts << " ";
  }

  cout << endl;
  string *pStartText = &texts[0];
  string *pEndText = &texts[2];
  while (true)
  {
    cout << *pStartText << " ";
    if (pStartText == pEndText)
      break;
    pStartText++;
  }

  return 0;
}