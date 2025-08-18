#include <iostream>
#include "cat.h"

using namespace std;

void Cat::speak()
{
  if (happy == true)
  {
    cout << "cat class speaking and cat meowing that is a happy cat..." << endl;
  }
  else
  {
    cout << "cat class speaking and cat Shhhh!!! cat is sad..." << endl;
  }
}

void Cat::makeHappy()
{
  happy = true;
}

void Cat::makeSad()
{
  happy = false;
}

bool Cat::catHappyState()
{
  return happy;
}
