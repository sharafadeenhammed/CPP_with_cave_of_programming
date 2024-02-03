#include <iostream>

using namespace std;

int main(int args, char **argv)
{
  const int N_STRINGS = 6;
  string animals[N_STRINGS] = {
      "dogs",
      "cats",
      "rabbits",
      "squirells",
      "elephants",
      "giraffes"};

  string *pAnimals = animals;

  pAnimals += 3;
  cout << *pAnimals << endl;

  pAnimals -= 2;
  cout << *pAnimals << endl;

  // resetting pAnimals to the start of the array.
  pAnimals = animals;
  string *pEnd = &animals[N_STRINGS];
  while (pAnimals != pEnd)
  {
    cout << *pAnimals << endl;
    pAnimals++;
  }
  // resetting pAnimals to the start of the array.
  pAnimals = animals;

  // subtracting pointers
  long length = pEnd - pAnimals;
  cout << length << endl;

  // going to the middle of an array
  pAnimals = animals;
  pAnimals += length / 2;
  cout << *pAnimals << endl;

  return 0;
}